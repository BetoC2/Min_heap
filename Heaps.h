#ifndef HEAPS_HEAPS_H


#define HEAPS_HEAPS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct priorityQueue PriorityQueue;
PriorityQueue *p_queue_new();
void p_queue_enqueue(PriorityQueue *pq, void *data, int priority);
void* p_queue_dequeue(PriorityQueue *pq);
int p_queue_empty(PriorityQueue *pq);


#endif //HEAPS_HEAPS_H
