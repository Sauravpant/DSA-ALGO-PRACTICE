/*
Problem: CombinationSumII
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate 
numbers sum to target.
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
*/

//Solution:
//  Approach: Simple backtracking approach with pick and not pick choice.Loop is used so that we can start trying combinations from a particuar index 
//beyond that index so as to avoid the duplicates and less recursive calls can be made

class Solution {
    void combination(int indx,int target,vector<vector<int>>&ans,vector<int> &arr,vector<int> ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=indx;i<arr.size();i++){
            if(i>indx && arr[i]==arr[i-1])
            continue;
            if(target<arr[i])
            break;
            ds.push_back(arr[i]);
            combination(i+1,target-arr[i],ans,arr,ds);
            ds.pop_back();   //Backtrack
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combination(0,target,ans,candidates,ds);
        return ans;
    
        
    }
};