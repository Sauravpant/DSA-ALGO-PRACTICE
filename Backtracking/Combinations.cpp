/*
77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/
//Solution:

class Solution {
    void combination(int indx,vector<int>&v,int target ,vector<vector<int>>& ans,vector<int>&ds){

            if(ds.size()==target){
            ans.push_back(ds);
            return;
            }
            if(indx>=v.size())
            return;
        ds.push_back(v[indx]);
        combination(indx+1,v,target,ans,ds);
        ds.pop_back(); //Backtrack
         combination(indx+1,v,target,ans,ds);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> temp;
        for(int i=1;i<=n;i++)
        temp.push_back(i);
        vector<int> ds;
         combination(0,temp,k,ans,ds);
         return ans;
        
    }
};