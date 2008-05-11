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
#include <sys/stat.h>

#include "dpl.h"
#include "file.h"

void fileOpen(dplVal *result, dplVal *path) {
	/* create a file pointer to the file at path */
	FILE_HANDLE(result) = fopen(FILE_PATH(path), "r");

	if(FILE_HANDLE(result) == NULL) {
		dplError(DPL_WARNINGL, "unable to open file");
	}
}

void fileRead(dplVal *result) {
	struct stat file;

	/* reset the file pointer */
	rewind(FILE_HANDLE(result));

	/* read file size */
	if(!stat(FILE_PATH(result), &file)) {
		FILE_SIZE(result) = file.st_size;
	}

	/* attempt to allocate enough memory for file */
	FILE_DATA(result) = (char *) malloc(FILE_SIZE(result) + 1);

	/* sanity check it */
	if(FILE_DATA(result) == NULL) {
		dplError(DPL_CORE, "unable allocate enough memory for file");
		return;
	}

	/* read in file */
	fread(FILE_DATA(result), 1, FILE_SIZE(result), FILE_HANDLE(result));
}
