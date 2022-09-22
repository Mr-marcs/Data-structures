#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE{
    int last,first,size,capacity;
    int* arr;
} queue_t;

queue_t* createQueue(int capacity){
    queue_t* my_queue = malloc(sizeof(queue_t));
    my_queue->capacity = capacity;
    my_queue->first = my_queue->size = 0;
    my_queue->last = -1;
    my_queue->arr = malloc(sizeof(int)*capacity);
    return my_queue;
}

void append(queue_t* queue,int val){
    if(queue->last == queue->capacity-1){
        queue->last = -1;
    }
    queue->arr[++queue->last] = val;
    queue->size++;
    return;
}

void printQueue(queue_t* queue){
    for(int i=0;i<queue->size;i++){
        printf("%d ",queue->arr[i]);
    }
    printf("\n");
}

int getMin(queue_t* queue){
    int min = queue->arr[0];
    for(int i=1;i<queue->size;i++){
        if(min > queue->arr[i])
            min = queue->arr[i];
    }
    return min;
}

int getMax(queue_t* queue){
    int max = queue->arr[0];
    for(int i=1;i<queue->size;i++){
        if(max < queue->arr[i])
            max = queue->arr[i];
    }
    return max;
}

float getAverage(queue_t* queue){
    float count = 0;
    for(int i=0;i<queue->size;i++){
        count += queue->arr[i];
    }
    return (float)(count/queue->size);
}

int main(){
    queue_t* queue = createQueue(5);
    append(queue,1);
    append(queue,8);
    append(queue,20);
    append(queue,2);
    append(queue,6);

    printQueue(queue);
    printf("Min -> %d\n",getMin(queue));
    printf("Max -> %d\n",getMax(queue));
    printf("Average -> %.1f\n",getAverage(queue));
}