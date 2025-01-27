#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<n+1;i++) {
            int number=i;
            int count=0;
            while(number!=0) {
                number=number&(number-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};