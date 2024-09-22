#include<stdio.h>
#include<stdlib.h>


/**
 * 操作：初始化、增删改查
 *      
 */
//----------------------第二种判空、判满方式-----------------------------------------------------------------------------------
typedef struct CycleQueue{
    int* data;
    int head;
    int tail;
    int size;
    int maxSize;
}CycleQueue;

CycleQueue* initCycleQueue(int capacity){
    CycleQueue* cycleQueue = (CycleQueue*)malloc(sizeof(CycleQueue));
    cycleQueue->data = (int*)malloc(sizeof(int)*capacity);
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
    if(queue->size == queue->maxSize){
        printf("该队列已经满，无法完成入列操作！\n");
        return 0;
    }
    queue->data[queue->tail] = el;
    queue->tail = (queue->tail+1)%(queue->maxSize);
    queue->size++;
    return 1;
}

//返回值为-1则出列失败
int pop(CycleQueue* queue){
    //判空
    if(isEmpty(queue)){
        printf("该队列为空，无法完成出列操作！\n");
        return -1;
    }
    int popResult = queue->data[queue->head];
    queue->head = (queue->head+1)%(queue->maxSize);
    queue->size--;
    return popResult;
}

//----------------------第一种判空、判满方式-----------------------------------------------------------------------------------
//空缺一个位置来实现判空，data[0]不允许入列
typedef struct CycleQueueX{
    int* data;
    int head;
    int tail;
    int maxSize;
}CycleQueueX;

CycleQueueX* initCycleQueueX(int capacity){
    CycleQueueX* cycleQueue = (CycleQueueX*)malloc(sizeof(int)*capacity);
    //使用空缺法就要注意，初始化链表产度要+1
    cycleQueue->data = (int*)malloc(sizeof(capacity+1));
    cycleQueue->head = 1;
    cycleQueue->tail = 1;
    //这里要尤其注意，因为数组的最大长度是容量加+1，由于用的是空缺法的原因
    cycleQueue->maxSize = capacity+1;
    return cycleQueue;
}


int isEmptyX(CycleQueueX* queue){
    return queue->head == queue->tail;
}

int lengthX(CycleQueueX* queue){
    return ((queue->tail)-(queue->head)+(queue->maxSize))%(queue->maxSize);
}

//返回值表示成功失败
int pushX(CycleQueueX* queue,int el){
    //判满
    if((queue->tail+1)%(queue->maxSize) == queue->head){
        printf("该队列已经满，无法完成入列操作！\n");
        return 0;
    }
    //从尾部入列
    queue->data[queue->tail] = el;
    //往前走一步，求余是因为考虑到循环的原因，指针到达数组末尾要归0
    queue->tail = ((queue->tail)+1) % (queue->maxSize);
    return 1;
}

//返回值为-1则出列失败
int popX(CycleQueueX* queue){
    if(isEmptyX(queue)){
        printf("该队列为空，无法完成出列操作！\n");
        return 0;
    }
    int popResult = queue->data[queue->head];
    //往前走一步
    queue->head = ((queue->head)+1) % (queue->maxSize);
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

    //-----------------空缺法判空、判满 循环链表---------------------------
    CycleQueueX* queueX = initCycleQueueX(5);
    printf("push result:%d \n",pushX(queueX,1));
    printf("push result:%d \n",pushX(queueX,5));
    printf("push result:%d \n",pushX(queueX,2));
    printf("push result:%d \n",pushX(queueX,12));
    printf("push result:%d \n",pushX(queueX,32));
    printf("%d \n",popX(queueX));
    printf("push result:%d \n",pushX(queueX,15));
    printf("isEmpty:%d \n",isEmptyX(queueX));
    printf("length:%d \n",lengthX(queueX));
    printf("push result:%d \n",pushX(queueX,19));
    printf("%d ",popX(queueX));
    printf("%d ",popX(queueX));
    printf("%d ",popX(queueX));
    printf("%d ",popX(queueX));
    printf("%d ",popX(queueX));
    printf("%d ",popX(queueX));
    printf("\n");
}