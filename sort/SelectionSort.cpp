#include<iostream>

using namespace std;

void swap(int data[],int length,int i, int j){
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}
//选择排序: 把较小的挪到前面
void selectionSort(int data[],int length){
    for(int i = 0 ; i < length ; i ++){
        int curMaxIndex = i;
        for(int j = i + 1 ; j < length ; j++){
            if(data[curMaxIndex] > data[j])curMaxIndex = j;
        }
        swap(data,length,i,curMaxIndex);
    }
}
int main(){
    int data[] = {7,3,6,5,2,4,1};
    cout << "排序前:";
    for(int i = 0 ; i < 7 ; i ++)cout << data[i] << " ";
    selectionSort(data,7);
    cout << "\n选择排序后:";
    for(int i = 0 ; i < 7 ; i ++)cout << data[i] << " ";
    cout << "\n";
}