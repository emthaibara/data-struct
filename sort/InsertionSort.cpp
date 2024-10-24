#include<iostream>
using namespace std;

void insertionSort(int arr[],int len){
    for(int i = 1 ; i < len ; i ++){
        int k = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > k){
            arr[j+1] = arr[j]; //这里我第一次写成了交换，虽然也对但是导致了很多重复交换，在这里挪位置就行了
            j--;
        }
        arr[j+1] = k; //下次需要注意，插入排序，不需要两两交换，只需要挪位置，直到找到合适位置再把待插入的元素插进来就行。
    }
}



int main(){
    int data[] = {8,2,6,3,10,9,4,1,7};
    cout << "排序前:";
    for(int i = 0 ; i < 9 ; i ++)cout << data[i] << " ";
    insertionSort(data,9);
    cout << "\n选择排序后:";
    for(int i = 0 ; i < 9 ; i ++)cout << data[i] << " ";
    cout << "\n";
}
