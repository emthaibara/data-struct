#include <stdio.h>
#include <stdlib.h>

typedef struct LinearList{
    int *data;
    int currentSize;
    int capacity;
}LinearList;

// 初始化线性表
void initLinearList(LinearList *list,int initCapacity){
    list->data = (int *)malloc(initCapacity * sizeof(int));
    list->currentSize = 0;
    list->capacity = initCapacity;
}

// 获取线性表长度
int length(LinearList *list){
    return list->currentSize;
}

// 按值查找，找到则返回索引，找不到返回-1
int locateElem(LinearList *list,int element){
    for(int i = 0 ; i < list->currentSize ; i++){
        if(list->data[i] == element)return i;
    }
    return -1;
}

// 按索引取值
int getElem(LinearList *list,int index){
    return list->data[index];
}

// 按索引插值
void listInsert(LinearList *list,int index,int element){
    if(list->capacity <= list->currentSize+1){
        printf("无法添加新的数据，该线性表存储空间已满");
        return;
    }
    int temp = list->data[index];
    int currentMoveElement;
    list->data[index] = element;
    list->currentSize++;
    for(int i = index+1 ; i < list->currentSize ; i++){
        currentMoveElement = list->data[i];
        list->data[i] = temp;
        temp = currentMoveElement;
    }
}

// 按索引删除
int listDelete(LinearList *list,int index,int element){
    if(list->currentSize < 1){
        printf("无法删除数据，该线性表未存储任何数据");
        return -1;
    }
    element = list->data[index];
    for(int i = index ; i < list->currentSize ; i++){
        list->data[i] = list->data[i+1];
    }
    list->currentSize--;
    return element;
}

// 打印线性表
void printList(LinearList *list){
    for (int i = 0 ; i < list->currentSize ; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 线性表判空
int empty(LinearList *list){
    if(list->currentSize <= 0 )return 1;
    else return 0;
}

// 销毁线性表 释放动态数据
void destroyList(LinearList *list){
    if(list->data != NULL){
        free(list->data);
        list->data = NULL;
    }
    list->currentSize = 0;
    list->capacity = 0;
}


// 作业综合应用题 1
void deleteMinElement(LinearList *list){
    if(list->currentSize <= 0){
        printf("删除失败，线性表为空");
    }else{
        //找到最小元素的索引
        int min = INT32_MAX; //用于比对大小
        int minIndex = -1;
        for(int i = 0 ; i < list->currentSize ; i++){
            if(min > list->data[i]){
                minIndex = i;
                min = list->data[i];
            }
        }
        //用最后一个元素替代
        list->data[minIndex] = list->data[list->currentSize-1];
        //最后一个元素置为0
        list->data[list->currentSize-1] = 0;
        //线性表大小减一
        list->currentSize--;
    }
}

// 作业综合应用题 2    
void reversalList(LinearList *list){
    int temp;
    int l = 0,r = list->currentSize-1;
    while(l > r){
        temp = list->data[l];
        list->data[l] = list->data[r];
        list->data[r] = temp;
        l++;
        r--;
    }
}

// 作业综合应用题 5
void deleteRepeatingElement(LinearList *list){
    //快慢指针，只要确保慢指针前面都是不重复就行
    int fast = 0 , slow = 0;
    int size = list->currentSize;
    for(int i = 0 ; i < size ; i ++){
        if(list->data[fast] != list->data[slow]){
            slow++;
            list->data[slow] = list->data[fast];
        }
        fast++;
    }
    //走完之后slow后面全都是重复的,挨个清零并修改线性表长度
    for(int i = slow+1; i < size ; i ++){
        list->data[i] = 0;
        list->currentSize--;
    }
}

int main(){
    LinearList *list = malloc(sizeof(LinearList));
    initLinearList(list,20);
    int index = 0;
    for (int el = 10; el > 0; el--){
        listInsert(list,index,el);
        index++;
    }
    printList(list);
    int e ;
    listDelete(list,2,e);
    printList(list);
}