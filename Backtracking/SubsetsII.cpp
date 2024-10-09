/*
90. Subsets II
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
/*

{    A backtracking approach    }. Loop is used so that we can start picking the elements from the respective index . The brute force approach is that
we can use set data structure consisting of vector instead of vector of vector while pushing the subsets which will avoid adding the duplicates in the set and
then finally return a vector of vector .This will take some extra time and space thus increasing the time and space complexities of the solution.
The optimised solution is to choose a starting index and then generate subset with that index value and  one index after that upto last index .
By doing this we avoid unnecessary recursive calls and also check for duplicates at each step so that no duplicates will be in the ans array.
Input array is sorted so that we can check for duplicates efficiently. the condition (   if(i!=indx&&arr[i]==arr[i-1])   ) ensures this where i!=indx implies
that we will add the duplcate only once initially.

*/

//Solution:

class Solution {
    void subset(int indx,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=indx;i<arr.size();i++){
        if(i!=indx&&arr[i]==arr[i-1])
        continue;
        ds.push_back(arr[i]);
        subset(i+1,arr,ds,ans);
        ds.pop_back(); //Backtrack
        } 
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subset(0,nums,ds,ans);
        return ans;
    }
};
