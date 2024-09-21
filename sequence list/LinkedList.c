#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}*LinkedList,Node;

//初始化链表
int initLinkedList(LinkedList* list){
    *list = (Node*)malloc(sizeof(Node));
    (*list)->next = NULL;
    return -1;
}

//通过尾插法构建
void genLinkedListByHeadInsert(LinkedList* list){
    *list = (Node*)malloc(sizeof(Node));
    (*list)->next = NULL;
    Node* newNode;
    int el;
    scanf("%d",&el);
    while(el != 888){
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = el;
        newNode->next = (*list)->next;
        (*list)->next = newNode;
        scanf("%d",&el);    
    }
}

//通过尾插法构建
void genLinkedByTailInseart(LinkedList* list){
    *list = (Node*)malloc(sizeof(Node));
    (*list)->next = NULL;
    Node* newNode;
    Node* tail = (*list);
    int el;
    scanf("%d",&el);
    while(el != 888){
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = el;
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
        scanf("%d",&el);
    }
}

// void remove(LinkedList* list){

// }

// void insert(LinkedList* list){

// }

// int length(LinkedList* list){

// }

// int set(){

// }

// int isEmpty(){
    
// }

void printfList(LinkedList* list){
    Node* head = (*list);
    while(head->next != NULL){
        head = head->next;
        printf("%d ",head->data);
    }
    printf("\n");
}

//逆置链表（带头节点） ：采用类似头插法的算法
void reversalList(LinkedList* list){
    Node *head = (*list);
    Node *pre = NULL; //记作新的首原节点
    Node *cur = head->next; //当前要插入头部的节点
    Node *temp; //临时存放cur的next
    while(cur != NULL){
        temp = cur->next;
        cur->next = pre;
        pre = cur; 
        cur = temp;
    }
    (*list)->next = pre;
}

int main(){
    LinkedList list;
    // initLinkedList(&list); //test succed
    // genLinkedListByHeadInsert(&list); //test succed
    genLinkedByTailInseart(&list); //test succed
    printfList(&list);
    reversalList(&list);//1 2 3 4 5 6 7 8 9 888
    printfList(&list);
    return 0;
}