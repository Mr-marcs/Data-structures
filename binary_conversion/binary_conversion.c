#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct stack{
    int capacity;
    int top;
    int *arr;
};

struct stack* create_stack(int capacity){
    struct stack* my_stack = malloc(sizeof(struct stack));
    my_stack->capacity = capacity;
    my_stack->top = -1;
    my_stack->arr = malloc(capacity * sizeof(int));
}

int isFull(struct stack* stack){
    return stack->top == stack->capacity;
}

int isEmpty(struct stack* stack){
    return stack->top == -1;
}

void push(struct stack* stack,int value){
    if(isFull(stack)){
        printf("Stack overflow!");
        return;
    }
    stack->arr[++stack->top] = value;
    return;
}

int pop(struct stack* stack){
    if(isEmpty(stack)){
        return -1;
    }
    stack->arr[stack->top--];
    return stack->arr[stack->top];
}

void printTop(struct stack* stack){
    printf("%d",stack->arr[stack->top]);
    return;
}


void printStackReverse(struct stack* stack){
    for(int i=stack->top;i>=0;i--){
        printf("%d",stack->arr[i]);
    }
    return;
}

int main(){
    int num;
    printf("Type the number: ");
    scanf("%d",&num);

    int capacity = floor(log(num)/log(2));

    struct stack *stack = create_stack(capacity);
    for(int i=0;i<capacity;i++){
        push(stack,num%2);
        if(num == 2){
            push(stack,1);
            break;
        }
        else if(num == 1){
            push(stack,0);
            break;
        }
        else{
            num = floor(num/2);
        }
        
    }
    printStackReverse(stack);
    return 0;
}