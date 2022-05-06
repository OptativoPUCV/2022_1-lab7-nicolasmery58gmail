#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * new = (Heap *)malloc(sizeof(Heap));
  new->heapArray = (heapElem *)malloc(3*sizeof(heapElem));
  new->capac = 3;
  new->size = 0;
  return new;

}
