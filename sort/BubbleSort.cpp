#include <iostream>
using namespace std;

void swap(int data[],int length,int i, int j){
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}
//冒泡排序：把较大的挪到后面
void bubbleSort(int data[],int length){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0 ; i < length-1 ; i++){
            if(data[i] > data[i+1]){
                flag = true;
                swap(data,length,i,i+1);
            }
        }
    }
}
void bubbleSortOptimize(int data[],int length){
    for(int l = length-1 ; l > 0 ; l--){
        for(int i = 0 ; i < l ; i++){
            if(data[i] > data[i+1]){
                swap(data,length,i,i+1);
            }
        }
    }
}
int main(){
    int data[] = {7,3,6,5,2,4,1};
    cout << "排序前:";
    for(int i = 0 ; i < 7 ; i ++)cout << data[i] << " ";
    bubbleSort(data,7);
    cout << "\n冒泡排序后:";
    for(int i = 0 ; i < 7 ; i ++)cout << data[i] << " ";

    bubbleSortOptimize(data,7);
    cout << "\n优化冒泡排序后:";
    for(int i = 0 ; i < 7 ; i ++)cout << data[i] << " ";
    cout << "\n";
}
