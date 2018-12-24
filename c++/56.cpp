#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> rern;
        vector<int> start,end;
        for (int i = 0; i < intervals.size(); ++i) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        for (int j = 0,k=0; j < intervals.size(); ++j) {

            //判断狭隘一个区间的起始值是否大于上一个区间的结束值,如果大于就说明两个区间不能连在一块
            //需要将上一个区间的结束值作为合并区间的结束值,因此一个合并区间就出现了
            //k的作用就是记录每一个合并区间的起始值
            if (j == intervals.size()-1 || start[j+1]>end[j]){
                rern.push_back(Interval(start[k],end[j]));
                k=j+1;
            }
        }
        return rern;
    }
};
int main() {
    Solution *s = new Solution;
    Interval interval(1,3);
    Interval interval1(2,6);
    Interval interval2(8,10);
    Interval interval3(15,18);
    vector<Interval> v{interval,interval1,interval2,interval3};
//    v[0]=interval;
//    v[1] = interval1;
//    v[2]=interval2;
//    v[3]=interval3;
    vector<Interval> v2 =s->merge(v);

    return 0;
}