#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for (int i = digits.size()-1; i >= 0; i--) {
            int num = (digits[i]+carry);
            if (num >= 10)
            {
                if (i==0 && num >=10)
                {
                    for (int j = digits.size() ; j >=0; j--) {
                        if (j==digits.size())
                        {
                            digits.push_back(digits[j-1]);
                        } else{

                            if (j>=2)
                            {
                                digits[j] = digits[j-1];
                            } else{
                                digits[i] = 1;
                                digits[i+1] = num-10;
                            }
                        }
                    }

                } else{
                    digits[i]=num-10;
                }
            } else{
                digits[i] = num;
                return digits;
            }

        }
        return digits;


    }
};
int main() {
    vector<int> digits ={9};
    Solution *s= new Solution;
    vector<int> vector1 =  s->plusOne(digits);
    for (int i = 0; i < vector1.size(); ++i) {
        cout<<vector1[i]<<" "<<endl;
    }
    return 0;
}