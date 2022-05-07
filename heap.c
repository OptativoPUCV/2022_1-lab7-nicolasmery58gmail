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
  if( pq->size != 0){
    return pq->heapArray[0].data;
  }
  return NULL; 

}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size >= pq->capac){
    pq->heapArray = realloc(pq->heapArray, (pq->capac*2 + 1)*sizeof(heapElem));
    pq->capac = pq->capac*2 +1;
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
  int aux;
  void * dat;

  aux = pq->heapArray[0].priority;
  pq->heapArray[0].priority = pq->heapArray[pq->size-1].priority;
  pq->heapArray[pq->size-1].priority = aux;
  dat = pq->heapArray[0].data;
  pq->heapArray[0].data = pq->heapArray[pq->size-1].data;
  pq->heapArray[pq->size-1].data = dat;
  pq->size -= 1;

  int place = 0;
  int leaf;
  while (2*place+1 < pq->size){
    leaf = 0;
    if(2*place+2 == pq->size){
      leaf = 2*place+1;
    }else{
      if(pq->heapArray[2*place+1].priority > pq->heapArray[2*place+2].priority){
        leaf = 2*place+1;
      }else{
        leaf = 2*place+2;
      }
    }
    if (pq->heapArray[place].priority < pq->heapArray[leaf].priority){
      int change = pq->heapArray[place].priority;
      pq->heapArray[place].priority = pq->heapArray[leaf].priority;
      pq->heapArray[leaf].priority = change;
      void * aux2 = pq->heapArray[place].data;
      pq->heapArray[place].data = pq->heapArray[leaf].data;
      pq->heapArray[leaf].data = dat;
    }else{
      break;
    }
  }
}

Heap* createHeap(){
  Heap * new = (Heap *)malloc(sizeof(Heap));
  new->heapArray = (heapElem *)malloc(3*sizeof(heapElem));
  new->capac = 3;
  new->size = 0;
  return new;

}
