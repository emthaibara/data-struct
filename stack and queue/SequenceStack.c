#include<stdio.h>
#include<stdlib.h>


typedef struct SequenceStack{
    int* data;
    int front;
    int rear;
    int maxSize;
}SequenceStack;


SequenceStack* initSequenceStack(int capacity){
    SequenceStack* stack = (SequenceStack*)malloc(sizeof(SequenceStack));
    stack->data = (int*)malloc(sizeof(int)*capacity);
    stack->front = 0;
    stack->rear = 0;
    stack->maxSize = capacity;
    return stack;
}
int isEmpty(SequenceStack* stack){
    return stack->rear == stack->front;
}

int length(SequenceStack* stack){   
    return (stack->rear) - (stack->front);
}           

int push(SequenceStack* stack,int el){
    //判满
    if(stack->rear >= stack->maxSize){
        printf("该栈已经满，无法完成进栈操作！\n");
        return -1;
    }
    stack->data[stack->rear++] = el;
    return 0;
}

int pop(SequenceStack* stack){
    //判空
    if(isEmpty(stack)){
        printf("该栈为空，无法完成弹栈操作！\n");
        return 0;
    }
    return stack->data[--stack->rear];
}


int main(){
    SequenceStack* stack = initSequenceStack(5);
    printf("push result:%d \n",push(stack,1));
    printf("%d \n",pop(stack));
    printf("push result:%d \n",push(stack,5));
    printf("push result:%d \n",push(stack,2));
    printf("push result:%d \n",push(stack,12));
    printf("push result:%d \n",push(stack,32));
    printf("%d \n",pop(stack));
    printf("push result:%d \n",push(stack,15));
    printf("isEmpty:%d \n",isEmpty(stack));
    printf("length:%d \n",length(stack));
    printf("push result:%d \n",push(stack,19));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("\n");
}