/*
78. Subsets
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
//Solution:

class Solution {
    void subset(int indx,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
        if(indx==arr.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[indx]);
        subset(indx+1,arr,ds,ans);
        ds.pop_back(); //Backtrack
        subset(indx+1,arr,ds,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset(0,nums,ds,ans);
        return ans;
        
        
    }
};