#include <stdio.h>
#include "Heaps.h"

int main() {
    PriorityQueue *pq = p_queue_new();

    p_queue_enqueue(pq, "Foo", 12);
    p_queue_enqueue(pq, "Bar", 11);
    p_queue_enqueue(pq, "Hola", 5);
    p_queue_enqueue(pq, "Mundo!", 10);
    p_queue_enqueue(pq, "ESTO ES URGENTE!", 0);


    while (!p_queue_empty(pq))
    {
        char* message = p_queue_dequeue(pq);
        printf("%s\n", message);
    }

    printf("XD");

    return 0;
}