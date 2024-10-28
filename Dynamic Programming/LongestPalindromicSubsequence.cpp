/*
516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 
*/

// Approach: If we reverse the same string amd then find the LCS of original string ans reverese string it will be the Longest palindromic Subsequence of that string

class Solution {
        int calcLength(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
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
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return calcLength(s,t);
        
    }
};