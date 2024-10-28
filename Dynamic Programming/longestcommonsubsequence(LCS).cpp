/*
1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
*/

// Approach:Instead of generating all the subseq and comparing linearly the subseq of both strings we can use pointers method where we keep two pointers say i and j at the end of both strings and
// then try out the possible things we can do:
// 1-> If the character at that index matches we add 1 to LCS and call function recursively by i-1 and j-1
// 2-> else we call the function for i-1,j and i,j-1 and take the max among both
// The base case will be if decrementing any index i or j we reach at -1 we return 0 indicating the end of string
// ---Since in tabulation we cant fill -1 state we shift the index ie we treat any index as a 1 lesser value that is i=i-1 and j=j-1 and dp array  is also declared 1 size more
// With this condition if we modify the base case we can say that if we reach at index 0 we can return -1 indicating end of string

class Solution {
    // Memoization(Top-Bottom DP)
    int findLength(int indx1,int indx2,string &s1,string &s2,vector<vector<int>> &dp){
        if(indx1==0 || indx2==0) 
          return 0;

        if(dp[indx1][indx2]!=-1)   return dp[indx1][indx2];
        if(s1[indx1-1]==s2[indx2-1])
        return dp[indx1][indx2]=1+findLength(indx1-1,indx2-1,s1,s2,dp);
        else
        return dp[indx1][indx2]=max(findLength(indx1-1,indx2,s1,s2,dp),findLength(indx1,indx2-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        //Tabulation(Bottom-Up )
        for(int i=0;i<=n;i++) 
          dp[0][i]=0;
        for(int j=0;j<=m;j++)
          dp[j][0]=0;
        for(int indx1=1;indx1<=m;indx1++){
            for(int indx2=1;indx2<=n;indx2++){
                if(text1[indx1-1]==text2[indx2-1])
                    dp[indx1][indx2]=1+dp[indx1-1][indx2-1];
                 else
                     dp[indx1][indx2]=max(dp[indx1-1][indx2],dp[indx1][indx2-1]);

            }
        }

        return dp[m][n];
    }
};
