#include <iostream>
#include <vector>

using namespace std;
//解法一在的编译器上运行正确，但是提交上去就报错
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m+n;
        while (m>=0 &&n>=0){
            if (nums1[--m]>nums2[--n]){//倒着比，将大数放在后面
                nums1[--size] = nums1[m];
                n++;//因为每次比较的时候先减一了，所以给对方加１
            } else{
                nums1[--size] = nums2[n];
                m++;
            }
        }
        while (n>=0){
            nums1[--size] = nums2[n--];
        }
    }
};
//解法二
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};


int main() {
    Solution *s = new Solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3,n = 3;
    (*s).merge(nums1,m,nums2,n);
    for (int i = 0; i < nums1.size(); ++i) {
        cout<<nums1[i]<<endl;
    }
    return 0;
}