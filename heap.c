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
  if(pq->heapArray[0].data != NULL){
    return pq->heapArray[0].data;
  }else{
   return NULL; 
  }
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
    pq->heapArray = realloc(pq->heapArray, (pq->capac*2 + 1)*sizeof(heapElem));
  }
  int ext = pq->size;
  int aux_p;
  void* aux_d;
  pq->heapArray[ext].priority = priority;
  pq->heapArray[ext].data = data;
  while((ext > 0) && (pq->heapArray[(ext-1)/2].priority < pq->heapArray[ext].priority)){
    aux_p = pq->heapArray[(ext-1)/2].priority;
    pq->heapArray[(ext-1)/2].priority = pq->heapArray[ext].priority;
    pq->heapArray[ext].priority = aux_p;
    aux_d = pq->heapArray[(ext-1)/2].data;
    pq->heapArray[(ext-1)/2].data = pq->heapArray[ext].data;
    pq->heapArray[ext].data = aux_d;
    ext = (ext-1)/2;
  }
  pq->size += 1;
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
