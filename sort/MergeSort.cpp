#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//归并操作  [....l<----->m<------->r....]
void mearge(vector<int>& nums,int l,int m,int r){
    //l<----->m已有序，m<------->r已有序
    int i = l, j = m+1, k = l;
    //拷贝一份nums用于辅助归并操作，因为归并操作没法原地进行
    vector<int> aux(nums); 
    while(i <= m && j <= r){ //有一个指针走到尾就结束
        if(aux[i] < aux[j]){
            nums[k++] = aux[i++];
        }else{
            nums[k++] = aux[j++];
        }
    }
    //判断哪一个走到底
    if(i == m+1 && j != r+1)while(j <= r)nums[k++] = aux[j++];
    if(j == r+1 && i != m+1)while(i <= m)nums[k++] = aux[i++];
}

//要完成归并排序有两个思路：1.分治法---自顶向下，用递归写 2.自底向上，用迭代写
//分治思想，递归实现如下
void divide(vector<int>& nums,int l,int r){
    if(l >= r)return;
    int mid = l + (r-l)/2; //这里写(r+l)/2会溢出
    divide(nums,l,mid);
    divide(nums,mid+1,r);
    mearge(nums,l,mid,r);
}

void meargeSort(vector<int>& nums){
    divide(nums,0,nums.size()-1);
}

int main(){
    vector<int> nums = {8,2,6,3,10,9,4,1,7};
    cout << "排序前:";
    for_each(nums.begin(),nums.end(),[](int e){cout << e << " ";});
    cout << "\n归并排序后:";
    meargeSort(nums);
    for_each(nums.begin(),nums.end(),[](int e){cout << e << " ";});
    cout << "\n";
}