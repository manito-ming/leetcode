#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for(int i = 0;i<height.size();i++){
            for(int j = i+1;j<height.size();j++){
                maxArea = max(maxArea,min(height[i],height[j])*(j-i));
            }
        }
        return maxArea;

    }
};
int main() {
    Solution *s = new Solution;
    vector<int> vector1={1,8,6,2,5,4,8,3,7};
    cout<<s->maxArea(vector1);
    return 0;
}