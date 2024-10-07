/*
216. Combination Sum III
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
*/

//Solution:

class Solution {
    void findCombination(int indx,int target,int range,vector<vector<int>>&ans,vector<int>&arr,vector<int>&ds){
        if(ds.size()==range){
            if(target==0){
            ans.push_back(ds);
            return;
            }
        }
        for(int i=indx;i<arr.size();i++){
            if(arr[i]>target)
            break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i],range,ans,arr,ds);
            ds.pop_back(); //Backtrack
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        vector<int>ds;
        vector<vector<int>> ans;
        for(int i=1;i<10;i++)
            arr.push_back(i);
        findCombination(0,n,k,ans,arr,ds);
        return ans;
        
    }
};