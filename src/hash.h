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

#ifndef _DPL_HASH
#define _DPL_HASH

#include <stdlib.h>

typedef struct _Bucket {
	char *key;
	int keyLen;

	unsigned int h;
	
	void *data;

	struct _Bucket *prev;
	struct _Bucket *next;

} Bucket;

typedef struct _HashTable {

	int isInit;
	
	int tableSize;
	int numElements;
	int nextFreeElement;
	
	Bucket *internalPointer;
	Bucket *head;
	Bucket *tail;
	Bucket **elements;

	void (*destroy)(void *data);

} HashTable;

extern int dplHashInit(HashTable *ht,int size,void (*destory)(void *data));
extern void dplHashDestroy(HashTable *ht);

extern int dplHashCopy(HashTable **target,HashTable *source,void (*cc) (void *data),void *tmp,int size);

extern int dplHashAddElement(HashTable *ht,char *key,int keyLen,void *data,int dataSize);
extern int dplHashUpdateElement(HashTable *ht,char *key,int keyLen,void *data,int dataSize);
extern int dplHashFind(HashTable *ht,char *key,int keyLen,void **data);
//extern int dpl_hash_del_element(HashTable *ht,char *key,int keyLen);

extern int dplHashAddIndexElement(HashTable *ht,unsigned int i,void *data,int dataSize);
extern int dplHashUpdateIndexElement(HashTable *ht,unsigned int i,void *data,int dataSize);
extern int dplHashIndexFind(HashTable *ht,unsigned int i,void **data);

extern void dplHashIndexDump(HashTable *ht,int fromInsert);
extern void dplHashDump(HashTable *ht);

#endif
