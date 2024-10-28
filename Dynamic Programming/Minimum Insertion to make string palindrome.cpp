/*
1312. Minimum Insertion Steps to Make a String Palindrome
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 
*/

// Approach: If we keep the LCS of that string intact and then put the reverse of remaining strings to left and write of LCS we can make the string plaindorme and total steps will be equal to the
// length of string-length of LCS of that string

class Solution {
    int calcMinLength(string &s1,string &s2){
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int j=0;j<=m;j++) dp[j][0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
public:
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int val=calcMinLength(s,t);
        return s.size()-val;    
    }
};