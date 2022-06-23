#include <stdlib.h>
#include <stdio.h>

typedef struct complexStruct {
  int                    val;
	struct complexStruct *prev;
	struct complexStruct *next;
} ComplexObj;

int main(void) {

  // We start with some simple arrays of int's and double's
  int *intArray = calloc(10, sizeof(int) );
  if (!intArray) return 1;
  // NOTE the following assertion FAILS if we do not ensure intArray is
  // not NULL!
  //@ assert \valid(intArray);
  for (int i = 0 ; i < 10; i++) intArray[i] = i;

  double *dblArray = calloc(10, sizeof(double));
  if (!dblArray) return 2;
  //@ assert \valid(dblArray);
  for (int i = 0 ; i < 10; i++) dblArray[i] = (double)i;


  // Now we calloc an array of complex structures

  ComplexObj *cObjArray = calloc(10, sizeof(ComplexObj));
  if (!cObjArray) return 3;
  //@ assert \valid(cObjArray);
  for (int i = 0; i < 9; i++) cObjArray[i].next = &cObjArray[i+1];

  // Now we calloc an array of pointers to complex structures

  ComplexObj **cObjPtrArray = (ComplexObj**)calloc(10, sizeof(ComplexObj*));
  if (!cObjPtrArray) return 4;
  //@ assert \valid(cObjPtrArray);
  for (int i = 0; i < 10; i++) {
  	cObjPtrArray[i] = calloc(1, sizeof(ComplexObj));
  	if (!cObjPtrArray[i]) return 5;
  	//@ assert \valid(cObjPtrArray[i]);
  }

  for (int i = 0; i < 9;  i++) cObjPtrArray[i]->next = cObjPtrArray[i+1];
  for (int i = 1; i < 10; i++) cObjPtrArray[i]->prev = cObjPtrArray[i-1];

	return 0;
}
