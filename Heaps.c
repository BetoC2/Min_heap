#include "Heaps.h"

typedef struct node{
    void *data;
    int priority;
} Node;

struct priorityQueue{
    Node *root;
    int size;
    int elements;
};

void swap(Node *a, Node *b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

PriorityQueue* p_queue_new(){
    PriorityQueue* array = malloc(sizeof(PriorityQueue));
    array->root = calloc(1,sizeof(Node));
    array->size = 1;
    array->elements = 0;
    return array;
}

void heapify_up(PriorityQueue *pq, int index){
    int papa = (index-1)/2;
    if(pq->root[index].priority < pq->root[papa].priority){
        swap(pq->root+index, pq->root+papa);
        heapify_up(pq, papa);
    }

}

void p_queue_enqueue(PriorityQueue *pq, void *data, int priority){
    Node queue_struct = {data, priority};
    if(pq->elements >= pq->size){
        pq->size *=2;
        pq->root = realloc(pq->root, sizeof(Node) * pq->size);
    }
    pq->root[pq->elements] = queue_struct;
    heapify_up(pq, pq->elements);
    pq->elements++;
}

void heapify_down(PriorityQueue *pq, int index) {
    int mijo = (2 * index) + 1;

    for (int i = 0; i < 2; i++) {
        if (pq->elements <= mijo)
            return;

        if (pq->root[index].priority > pq->root[mijo].priority) {
            swap(pq->root + index, pq->root + mijo);
            heapify_down(pq, mijo);
        }
        mijo++;
    }
}

void* p_queue_dequeue(PriorityQueue *pq){
    Node save = pq->root[0];
    pq->elements--;
    swap(pq->root, pq->root+(pq->elements));
    heapify_down(pq, 0);
    return save.data;
}

int p_queue_empty(PriorityQueue *pq){
    if(pq->elements > 0)
        return 0;
    return 1;
}