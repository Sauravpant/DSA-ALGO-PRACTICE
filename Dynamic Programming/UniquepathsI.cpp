// Problem: Unique Paths
/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

*/

/*
Approach: Write the recurrence relation: We can move either right or bottom and if we start from the ending point ie the destination it is just opposite that is bottom is up and left is right
The steps for writing any recurrence relation are:
1.Express the problem in terms of index and write down the base case according to the question,(If we have to count the ways we return either  0 or 1 form the base case depending upon the problem)
2.Do all possible stuff on that index.
3.Return what is required

*/
#include<bits/stdc++.h>
using namespace std;


// Memoization solution

class Solution {
    int findPaths(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=findPaths(i-1,j,dp);
        int left=findPaths(i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return findPaths(m-1,n-1,dp);
        
    }
};


//Tabulation with space optimisation
// Any DP solution can be space optimised if we just require the previous state

class Solution {
    public:
        int uniquePaths(int m, int n){
            vector<int> prev(n,0);
            for(int i=0;i<m;i++){
                vector<int> temp(n,0);
                for(int j=0;j<n;j++){
                    if(i==0 && j==0)
                    temp[0]=1;
                    else{
                        int bottom=0;
                        int right=0;
                        if(i>0) bottom=prev[j];
                        if(j>0) right=temp[j-1];
                        temp[j]=bottom+right;
                    }

                }
                prev=temp;
            }
            return prev[n-1];
        }
};



