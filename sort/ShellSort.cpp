#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//设置哨兵nums[0]
void shellSort(vector<int>& nums){
    //第一个位置放置哨兵
    int len = nums.size();
    nums.insert(nums.begin(),-1);
    int d = len/2;
    while(d >= 1){
        for(int i = d+1 ; i < len+1 ; i++){
            if(nums[i] < nums[i-d]){
                //设置哨兵元素为待插入元素nums[i]
                nums[0] = nums[i];
                int j;
                //找到第一个小于或等于nums[0]的
                for(j = i-d ; j > 0 && nums[j] > nums[0]; j-=d){
                    nums[j+d] = nums[j];
                }
                nums[j+d] = nums[0];
            }
        }
        d/=2;
    }
    nums[0] = -1;
}

int main(){
    vector<int> nums = {8,2,6,3,10,9,4,1,7};
    cout << "排序前:";
    for(int i = 0 ; i < 9 ; i ++)cout << nums[i] << " ";
    shellSort(nums);
    cout << "\n选择排序后:";
    for(int i = 1 ; i < 10 ; i ++)cout << nums[i] << " ";
    cout << "\n";
}