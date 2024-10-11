#include<bits/stdc++.h>
using namespace std;
/*
39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen
 numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

*/

//Solution :
/*
A backtracking approach:
we can form the combination using take and not take option, If we take an element from a current index the target reduces by the value at that current index
and for that the target must be either smaller or equal to that index value.if at any instant we reach to last index and our target becomes 0 we have 
that combination that adds up to the target and we push it to our ans . And for no take condition we simply move to the last index and our target remains 
same,
*/
class Solution{
    void combination(int indx,int target,vector<int>&arr,vector<vector<int>>&Ans,vector<int>&ds){
        if (indx==arr.size())
        {
            if(target==0)
            Ans.push_back(ds);
            else
            return;
        }
        if(arr[indx]<=target){
        ds.push_back(arr[indx]);
        combination(indx,target-arr[indx],arr,Ans,ds);
        ds.pop_back();
        combination(indx+1,target,arr,Ans,ds);
        }
        

    }
    public:
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ds;
    vector<vector<int>> combinationAns;
    combination(0,target,candidates,combinationAns,ds);
    return combinationAns;

     }

};