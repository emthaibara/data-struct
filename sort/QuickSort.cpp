#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;

void swap(vector<int>& nums, int i , int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int partition(vector<int>& nums, int l, int r){
    int pivot = nums[l];
    int i = l ,j = r;
    while(i <= j){
        while(i <= j && nums[i] <= pivot){++i;};
        while(i <= j && nums[j] >= pivot){--j;};
        if(i < j)swap(nums, i ,j);
    }
    swap(nums, l, j);
    return j;
}
//用分治的思想：每一次找切分点都会让局部有序，每一个局部都有序最终会整体有序，和归并排序是一个思路，只不过这里每次不是合并数组
void divid(vector<int>& nums, int l, int r){
    if(l >= r)return;
    int cut = partition(nums,l,r);
    cout << "\n:";
    for_each(nums.begin(),nums.end(),[](int e){cout << e << " ";});
    //分治
    divid(nums,l,cut-1);
    divid(nums,cut+1,r);
}
void quickSort(vector<int>& nums){
    //打乱数组
    random_device rd;
    mt19937 g(rd());
    shuffle(nums.begin(),nums.end(),g);
    divid(nums, 0, nums.size()-1);
}

int main(){
    vector<int> nums = {8,2,6,3,10,9,4,1,7};
    cout << "排序前:";
    for_each(nums.begin(),nums.end(),[](int e){cout << e << " ";});
    quickSort(nums);
    cout << "\n快速排序后:";
    for_each(nums.begin(),nums.end(),[](int e){cout << e << " ";});
    cout <<"\n";
}


