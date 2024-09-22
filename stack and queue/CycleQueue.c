#include<stdio.h>
#include<stdlib.h>


/**
 * 操作：初始化、增删改查
 *      
 */

typedef struct CycleQueue{
    int* data;
    int head;
    int tail;
    int size;
    int maxSize;
}CycleQueue;

CycleQueue* initCycleQueue(int capacity){
    CycleQueue* cycleQueue = (CycleQueue*)malloc(sizeof(CycleQueue));
    cycleQueue->data = (int*)malloc(sizeof(capacity));
    cycleQueue->head = 0;
    cycleQueue->tail = 0;
    cycleQueue->size = 0;
    cycleQueue->maxSize = capacity;
    return cycleQueue;
}

int isEmpty(CycleQueue* queue){
    return queue->size == 0;
}

int length(CycleQueue* queue){
    return queue->size;
}

//返回值表示成功失败
int push(CycleQueue* queue,int el){
    //判满
    if(queue->size == queue->maxSize)return 0;
    queue->data[queue->tail] = el;
    queue->tail = (queue->tail+1)%(queue->maxSize);
    queue->size++;
    return 1;
}

//返回值为-1则出列失败
int pop(CycleQueue* queue){
    //判空
    if(isEmpty(queue))return -1;
    int popResult = queue->data[queue->head];
    queue->head = (queue->head+1)%(queue->maxSize);
    queue->size--;
    return popResult;
}

int main(){
    CycleQueue* queue = initCycleQueue(5);

    printf("push result:%d \n",push(queue,1));
    printf("push result:%d \n",push(queue,5));
    printf("push result:%d \n",push(queue,2));
    printf("push result:%d \n",push(queue,12));
    printf("push result:%d \n",push(queue,32));
    printf("%d \n",pop(queue));
    printf("push result:%d \n",push(queue,15));
    printf("isEmpty:%d \n",isEmpty(queue));
    printf("length:%d \n",length(queue));
    printf("push result:%d \n",push(queue,19));
    
    printf("%d ",pop(queue));
    printf("%d ",pop(queue));
    printf("%d ",pop(queue));
    printf("%d ",pop(queue));
    printf("%d ",pop(queue));
    printf("%d ",pop(queue));
    printf("\n");
}