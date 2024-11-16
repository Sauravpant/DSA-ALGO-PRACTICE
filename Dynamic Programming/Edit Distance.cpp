/* 
72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
*/

// Approach: If characters of word1 and word2 at index i and j match we shrink the strings and compare the next character else we can peroform 3 operations:
// Insert a character: Hypothetically if we insert a character we will insert the matching character at the position just after what we are comapring of word 1 so we keep index i same and reduce
// j assuming we have inserted the character just after that character in word1 and now we are searching for j-1 th character of word2 in word1-> count the move
// Delete: We assume we have deleted that character in word i so count the move shrink the word1 by 1
// Replace: We assume we have replaced the word2[j] the charcater in word1[i] so count move and the string by 1


class Solution {
    //Memoization Solution
    int calcSteps(int i,int j,string &s,string &t,vector<vector<int>> &dp){

        if(i==0)  return j;
        if(j==0)  return i;

        if(dp[i][j]!=-1) 
        return dp[i][j];
        if(s[i-1]==t[j-1])
        return dp[i][j]=0+calcSteps(i-1,j-1,s,t,dp);
        else
        return dp[i][j]=min({1+calcSteps(i,j-1,s,t,dp),1+calcSteps(i-1,j,s,t,dp),1+calcSteps(i-1,j-1,s,t,dp)});

    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));  // return calcSteps(m,n,word1,word2,dp); //For memoization

        //Tabulation Solution 

        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int j=0;j<=n;j++) dp[0][j]=j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=0+dp[i-1][j-1];
                else
                    dp[i][j]=min({1+dp[i][j-1],1+dp[i-1][j],1+dp[i-1][j-1]});
            }
        }
        return dp[m][n];
        
    }
};