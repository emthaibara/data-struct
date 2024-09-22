#include<stdio.h>
#include<stdlib.h>

typedef struct SequenceQueue{
    int* data;
    int front; //队头
    int rear;   //队尾
    int maxSize;
}SequenceQueue;

SequenceQueue* initSequenceQueue(int capacity){
    SequenceQueue* queue = (SequenceQueue*)malloc(sizeof(SequenceQueue));
    queue->data = (int*)malloc(sizeof(int)*capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->maxSize = capacity;
    return queue;
}

int isEmpty(SequenceQueue* queue){
    return (queue->front) == (queue->rear);
}

int length(SequenceQueue* queue){
    return (queue->front)-(queue->rear);
}   


int push(SequenceQueue* queue,int el){
    //判满
    if(queue->rear >= queue->maxSize){
        printf("该队列已经满，无法完成入列操作！\n");
        return 0;
    }
    queue->data[queue->rear++] = el;
    return 1;
}

int pop(SequenceQueue* queue){
    //判空
    if(isEmpty(queue)){
        printf("该队列为空，无法完成出列操作！\n");
        return 0;
    }
    return queue->data[queue->front++];
}

int main(){
    SequenceQueue* queue = initSequenceQueue(10);
    printf("push result:%d \n",push(queue,1));
    printf("%d \n",pop(queue));
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
