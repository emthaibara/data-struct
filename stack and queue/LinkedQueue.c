#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

//带头节点的链式队列
typedef struct LinkedQueue{
    struct Node* head;
    int size;
}LinkedQueue;

LinkedQueue* initLinkedQueue(){
    //初始化链队列
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    queue->head = (Node*)malloc(sizeof(Node));
    //初始化链队列头节点
    queue->head->next = NULL;
    queue->head->data = -1;
    //初始化队列长度
    queue->size = 0;
    return queue;
}

int isEmpty(LinkedQueue* queue){
    return queue->size == 0;
}

int length(LinkedQueue* queue){
    return queue->size;
}

/**
 * 采用尾插法
 *  1.做法一：每次push遍历链表找到tail ✅
 *  2.做法二：设置一个尾指针，始终指向tail，减少时间复杂度
 **/
int push(LinkedQueue* queue,int el){
    Node* temp = queue->head;
    Node* tail = queue->head;
    // find tail
    while(temp->next != NULL){
        temp = temp->next;
        tail = temp;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    //链式存储无需判满，但需要注意堆内存溢出
    if(newNode == NULL){
        printf("堆内存溢出，为新的节点分配内存失败 \n");
        return -1;
    }
    newNode->next = NULL;
    newNode->data = el;
    tail->next = newNode;
    queue->size++;
    return 0;
}

//从头部出列 === 删除首元节点
int pop(LinkedQueue* queue){
    //判空
    if(isEmpty(queue)){
        printf("该队列为空，无法完成出列操作！\n");
        return -1;
    }
    //预留当前出列节点指针，方便free
    Node* popNode = queue->head->next;
    int popResult = popNode->data;
    //pop操作
    queue->head->next = queue->head->next->next;
    free(popNode);
    queue->size--;
    return popResult;
}

int main(){
    LinkedQueue* queue = initLinkedQueue();
    printf("push %d , push result: %d \n",1,push(queue,1));
    printf("push %d , push result: %d \n",12,push(queue,12));
    printf("pop result:%d \n",pop(queue));
    printf("push %d , push result: %d \n",31,push(queue,31));
    printf("push %d , push result: %d \n",3,push(queue,3));
    printf("pop result:%d \n",pop(queue));
    printf("pop result:%d \n",pop(queue));
    printf("pop result:%d \n",pop(queue));
    printf("push %d , push result: %d \n",4,push(queue,4));
    printf("pop result:%d \n",pop(queue));
}