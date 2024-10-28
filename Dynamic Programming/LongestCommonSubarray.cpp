/*
Leetcode-718. Maximum Length of Repeated Subarray
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
 
Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
*/

// Approach: Since we have to find the length of longest common subarray we only care about the consecutive matches and if value at any index doesnt matches we assign it 0,if they match we check 
// back the previous state to ensure if the numbers before them had matched or not if so we add that to current value . The length of the longest common subarray will be the maximum length stored
// in the dp table . This can also be Space optimized since we are requiring only the value of previous state.

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //Tabulation(Bottom-Up )
        for(int i=0;i<=n;i++) 
          dp[0][i]=0;
        for(int j=0;j<=m;j++)
          dp[j][0]=0;   int ans=0;
        for(int indx1=1;indx1<=m;indx1++){
            for(int indx2=1;indx2<=n;indx2++){
                if(nums1[indx1-1]==nums2[indx2-1]){
                    dp[indx1][indx2]=1+dp[indx1-1][indx2-1];
                    ans=max(ans,dp[indx1][indx2]);
                }
                 else
                     dp[indx1][indx2]=0;
            }
        }
        return ans;   
    }
};
 