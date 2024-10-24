#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 堆的操作：
 *  插入<==>上浮
 *  删除<==>下沉
 * 二叉堆的存储：
 *  由于堆的特性是一颗完全二叉树，不妨设某节点的编号为i,左孩子为2i,右孩子为2i+1,
 *  二叉堆的性质可得：heap[i] > heap[2i] && heap[i] > heap[2i+1]
 *  很显然可以用随机存储的顺序表来存储二叉堆。
 */
//上浮
void up(vector<int>& heap,int x){
    //一直跟父亲比较就行,这里左右孩子虽然求父亲的公式不一样，但是计算机默认向下取整丢弃小数部分，所以统一的写x/=2就行
    while(x > 1 && heap[x/2] < heap[x]){
        swap(heap[x/2],heap[x]);
        x/=2;
    }
}
//下沉
void sink(vector<int>& heap,int x,int length){
    int child;
    while(x*2 <= length){
        child = x*2;
        if(child+1 <= length && heap[child+1] > heap[child])child++; //挑选较大的孩子
        if(heap[x] >= heap[child])break; //根大于孩子就结束
        swap(heap[child],heap[x]);
        x = child;
    }
}
void insert(vector<int>& heap,int el){
    //把待插入元素加到堆的最底层最右侧的叶子
    heap.push_back(el);
    //然后进行上浮操作
    up(heap, heap.size());    
}
//二叉堆的删除操作是删除堆中最大的元素
void remove(vector<int>& heap){
    //二叉堆的删除操作如下：先把最大的和最底下的元素交换，再删除最大的，再让根下沉。
    swap(heap[1],heap[heap.size()-1]);
    heap.pop_back();
    sink(heap, 1, heap.size()-1);
}

void heapSort(vector<int>& nums){
    //堆要做除法找孩子，不能从0开始，要从1开始
    nums.insert(nums.begin(),-1);
    //堆化：自底向上的遍历根元素并挨个下沉，最终得到堆
    for(int k = (nums.size()-1)/2 ; k > 0 ; k--)sink(nums,k,nums.size()-1);
    //类似删除操作，但是不会删掉，就放到末尾不动
    int count = nums.size()-1;
    while(count > 1){
        swap(nums[1],nums[count--]);
        sink(nums,1,count);
    }
}
int main(){
    vector<int> nums = {8,2,6,3,10,9,4,1,7};
    cout << "排序前:";
    for(int i = 0 ; i < 9 ; i ++)cout << nums[i] << " ";
    heapSort(nums);
    cout << "\n堆排序后:";
    for(int i = 1 ; i < 10 ; i ++)cout << nums[i] << " ";
    cout << "\n";
}