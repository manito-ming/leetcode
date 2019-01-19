#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//STL的sort()算法，数据量大时采用Quick Sort，分段递归排序。
// 一旦分段后的数据量小于某个阈值，为避免Quick Sort的递归调用带来过大的额外开销，就改用Insertion Sort（插入排序）
// 。如果递归层次过深，还会改用Heap Sort(堆排序)。
class Solution {
public:

    //我直接使用了c++系统封好的库函数去排序
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
            return nums[k-1];
    }

};
bool sorrt(int a,int b){
    return a>b;
}
int main() {
    Solution *s = new Solution;
    vector<int> v = {3,2,1,5,6,4};
//    sort(v.begin(),v.end(),sorrt);//这个是使用sort函数从大到校排序的另一种方法
    cout<<s->findKthLargest(v,2);

    return 0;
}