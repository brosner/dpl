/* 
   +----------------------------------------------+
   | DPL Programming Language v1.1                |
   +----------------------------------------------+
   | The DPL langauge was developed for a school  |
   | project at ThunderRidge High School.         |
   |                                              |
   | Development of the language after its        |
   | completion is reserved to Brian Rosner.      |
   +----------------------------------------------+
   | Author: Brian Rosner <br@brosner.com>        |
   +----------------------------------------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dpl.h"
#include "hash.h"

static unsigned long int hashpjw(char *key,int keyLen) {
	unsigned long int h = 0, g;
	char *end = key + keyLen;

	//printf("hashpjw = %s\n",key);

	while (key < end) {
		h = (h << 4) + *key++;
		if ((g = (h & 0xF0000000))) {
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}
	
	return h;
}

int dplHashInit(HashTable *ht,int size,void (*destroy)(void *data)) {
	if(size < 1) {
		ht->isInit = FALSE;
		return FAILURE;
	}

	/* allocate memory for elements */
	if((ht->elements = (Bucket **)malloc(size * sizeof(Bucket))) == NULL) {
		ht->isInit = FALSE;
		return FAILURE;
	}

	/* assign attributes */
	ht->tableSize = size;
	ht->numElements = 0;
	ht->nextFreeElement = 0;
	ht->internalPointer = NULL;
	ht->head = NULL;
	ht->tail = NULL;
	ht->destroy = destroy;

	ht->isInit = TRUE;

	return SUCCESS;
}

int dplHashAddElement(HashTable *ht,char *key,int keyLen,void *data,int dataSize) {
	unsigned long int h;
	int index;
	Bucket *p;

	if(keyLen <= 0) {
		return FAILURE;
	}

	h = hashpjw(key,keyLen);
	index = h % ht->tableSize;

	p = (Bucket *)malloc(sizeof(Bucket));
	if(!p) {
		return FAILURE;
	}

	p->key = (char *)malloc(keyLen);
	if(!p->key) {
		free(p);
		return FAILURE;
	}

	p->data = (void *)malloc(dataSize);
	if(!p->data) {
		free(p);
		free(p->key);
		return FAILURE;
	}

	p->keyLen = keyLen;
	memcpy(p->key,key,keyLen);
	memcpy(p->data,data,dataSize);

	if(ht->internalPointer == NULL) {
		ht->internalPointer = p;
	}

	ht->elements[index] = p;

	if(ht->numElements == 0) {
		ht->tail = p;
	}

	p->next = ht->head;
	ht->head = p;

	ht->numElements++;

	return SUCCESS;
}

int dplHashUpdateElement(HashTable *ht,char *key,int keyLen,void *data,int dataSize) {
	unsigned long int h;
	int index;
	Bucket *p;

	h = hashpjw(key,keyLen);
	index = h % ht->tableSize;

	p = ht->elements[index];
	
	while(p != NULL) {
		if((p->key != NULL) && (strcmp(p->key,key) == 0) && (p->keyLen == keyLen)) {

			if(ht->destroy) {
				ht->destroy(p->data);
			}

			memcpy(p->data,data,dataSize);

			return SUCCESS;
		}

		p = p->next;
	}
}

int dplHashFind(HashTable *ht,char *key,int keyLen,void **data) {
	unsigned long int h;
	int index;
	Bucket *p;

	h = hashpjw(key,keyLen);
	index = h % ht->tableSize;

	p = ht->elements[index];
#ifdef DEBUG
	if(p == NULL) {
		printf("p is null on key %s of index %d\n",key,index);
	}
#endif
	
	while(p != NULL) {
		if((p->key != NULL) && (strcmp(p->key,key) == 0) && (p->keyLen == keyLen)) {
			if(!memcmp(p->key,key,keyLen)) {
				*data = p->data;
				return SUCCESS;
			}
		}
		p = p->next;
	}

	return FAILURE;
}

/*int dplHashDelElement(HashTable *ht,char *key,int keyLen) {
	unsigned long int h;
	Bucket *p,*t;

	h = hashpjw(key,keyLen);
	index = h % ht->tableSize;

	p = ht->elements[index];

	while(p != NULL) {
		if((p->key != NULL) && (p->keyLen == keyLen) && (!memcmp(p->key,key,keyLen))) {
			if(p == ht->elements[index]) {
				ht->elements[index] = p->next;
			}
			else {
				t->next = p->next;
			}


		}
	}


}*/

int dplHashAddIndexElement(HashTable *ht,unsigned int i,void *data,int dataSize) {
	unsigned int index;
	Bucket *p;

	index = i % ht->tableSize;

	//printf("dplhaie index = %d\n",index);

	p = (Bucket *)malloc(sizeof(Bucket));
	
	if(!p) {
		return FAILURE;
	}

	p->key = NULL;
	p->keyLen = 0;
	p->h = index;
	p->data = (void *)malloc(dataSize);

	if(!p->data) {
		free(p->data);
		return FAILURE;
	}

	memcpy(p->data,data,dataSize);

	if(ht->internalPointer == NULL) {
		ht->internalPointer = p;
	}

	ht->elements[index] = p;

	if(ht->numElements == 0) {
		ht->tail = p;
	}

	p->next = ht->head;
	ht->head = p;

	ht->numElements++;

	return SUCCESS;
}

int dplHashUpdateIndexElement(HashTable *ht,unsigned int i,void *data,int dataSize) {
	unsigned int index;
	Bucket *p;

	index = i % ht->tableSize;

	p = ht->elements[index];

	if(ht->destroy) {
		//ht->destroy(p->data);
	}

	memcpy(p->data,data,dataSize);

	return SUCCESS;
}

int dplHashIndexFind(HashTable *ht,unsigned int i,void **data) {
	unsigned int index;
	Bucket *p;

	index = i % ht->tableSize;

#ifdef DEBUG
	printf("hash index find spill (tblsize = %d,i = %d,index = %d)\n",ht->tableSize,i,index);
#endif

	/* optimize away empty hash tables */
	if(ht->numElements == 0) {
		#ifdef DEBUG
		printf("dieing out due to no elements\n");
		#endif
		return FAILURE;
	}

	p = ht->elements[index];

#ifdef DEBUG
	printf("element spill (p is null = %s)\n",((p == NULL) ? "yes":"no"));
#endif

	while(p != NULL) {
		//printf("hash index find #%d\n",p->h);
		if((p->h == i) && (p->key == NULL)) {
			*data = p->data;
			return SUCCESS;
		}

		p = p->next;
	}


	return FAILURE;
}

int dplHashCopy(HashTable **target,HashTable *source,void (*cc) (void *data),void *tmp,int size) {
	HashTable *t;
	Bucket *p;

	//printf("performing a copy\n");
	//printf("^^ %p\n",source->head);

	/* allocate memory for target hash table */
	t = (HashTable *) malloc(sizeof(HashTable));

	if(!t) {
		*target = NULL;
		return FAILURE;
	}

	/* initialize target hash table */
	if(dplHashInit(t,source->tableSize,source->destroy) == FAILURE) {
		*target = NULL;
		return FAILURE;
	}

	/* start at source head and copy over each element */
	p = source->head;
	while(p) {
		memcpy(tmp,p->data,size);
		cc(tmp);

		if(p->key) {
			dplHashAddElement(t,p->key,p->keyLen,tmp,size);
		}
		else {
			dplHashAddIndexElement(t,p->h,tmp,size);
		}

		p = p->next;
	}

	t->internalPointer = t->head;
	*target = t;

	return SUCCESS;
}

void dplHashIndexDump(HashTable *ht,int fromInsert) {
	Bucket *p;

	/* start at start */
	p = ht->elements[ht->numElements - 1];

	while(p != NULL) {
		if(fromInsert == TRUE) { fprintf(stderr,"from insert\n"); }
		fprintf(stderr,"index = %d\n",p->h);
		fprintf(stderr,"data = %p\n",p->data);
		fprintf(stderr,"next = %p\n\n",p->next);
		p = p->next;
	}
}

void dplHashDump(HashTable *ht) {
	Bucket *p;

	/* start at start */
	p = ht->elements[0];

	while(p != NULL) {
		fprintf(stderr,"key = %d\n",p->key);
		fprintf(stderr,"data = %p\n",p->data);
		fprintf(stderr,"next = %p\n\n",p->next);
		p = p->next;
	}
}

void dplHashDestroy(HashTable *ht) {
	Bucket *c,*n;

	n = ht->head;
	while(n != NULL) {
		c = n;
		n = n->next;

		if(ht->destroy) {
			ht->destroy(c->data);
		}

		if(c->data) {
			free(c->data);
		}

		if(c->key) {
			free(c->key);
		}

		free(c);
	}

	free(ht->elements);
}
