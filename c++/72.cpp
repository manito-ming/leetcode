#include <iostream>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int d[n1+1][n2+1];
        for (int i = 0; i <= n1; ++i) {
            d[i][0] = i;
        }
        for (int i = 0; i <= n2; ++i) {
            d[0][i] = i;
        }
        for (int j = 1; j < n1+1 ; ++j) {
            for (int k = 1; k < n2+1 ; ++k) {
                if (word1[j-1] == word2[k-1]){
                    d[j][k] = d[j-1][k-1];
                } else{
                    d[j][k] = min(d[j-1][k-1],min(d[j-1][k],d[j][k-1]))+1;
                }
            }
        }
        return d[n1][n2];
    }
};



int main() {
    Solution *s = new Solution;
    string string1="horse";
    string string2="ros";
    cout<<s->minDistance(string1,string2);
    return 0;
}