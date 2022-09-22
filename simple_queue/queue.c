#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE{
    int first,last,size;
    int capacity;
    int *items;
} queue_t;

queue_t* createQueue(int capacity){
    queue_t* my_queue = malloc(sizeof(queue_t));
    my_queue->capacity = capacity;
    my_queue->items = malloc(capacity * sizeof(int));
    my_queue->first = 0;
    my_queue->size = 0; 
    my_queue->last = -1;
    return my_queue;
}

// int isFull(queue_t* queue){
//     return queue->size == queue->capacity;
// }

void append(queue_t* queue,int val){
   
    if(queue->last == queue->capacity-1){
        queue->last = -1;
    }
    queue->items[++queue->last] = val;
    queue->size++;
    return;
}

// int removeQueue(queue_t* queue){
//     int temp = queue->items[queue->first++];
//     if(queue->first == queue->capacity)
//         queue->first = 0;
//     queue->size--;
//     return temp;
// }

void printQueue(queue_t* queue){
    for(int i=queue->first;i < queue->capacity;i++){
        printf(" %d",queue->items[i]);
    }
    printf("\n");
    return;
}

void printQueueInStackFormat(queue_t* queue){
    for(int i=queue->last;i >= 0;i--){
        printf(" %d",queue->items[i]);
    }
    printf("\n");
    return;
}

int main(){
    queue_t* queue = createQueue(10);
    append(queue,7);
    append(queue,8);
    append(queue,10);
    append(queue,20);
    append(queue,30);
    append(queue,40);
    append(queue,50);
    append(queue,60);
    append(queue,70);
    append(queue,80);

    printf("Queue print ->");
    printQueue(queue);

    printf("Stack print ->");
    printQueueInStackFormat(queue);
    return 0;
}