/*
Problem Statement:  A thief is robbing a store and can carry a maximum weight of W in his Knapsack.There are N items and ith items weighs wi and value vi.Considering the constraints of maximum
weight that a Knapsack can carry,you have to find the maximum value that a thief can generate by stealing items 
*/


#include<bits/stdc++.h>
using namespace std;

// Memoization Solution(Top-Bottom DP)
int fun(int indx,vector<int>&wt,int maxWt,vector<int>&value,vector<vector<int>>&dp){
    if(indx==0){
        if(wt[0]<=maxWt)  return value[0];
        else return 0;
    }
    if(dp[indx][maxWt]!=-1)
     return dp[indx][maxWt];
     int notTake=fun(indx-1,wt,maxWt,value,dp);
     int take=INT_MIN;
     if(wt[indx]<=maxWt)  take=value[indx]+fun(indx-1,wt,maxWt-wt[indx],value,dp);

     return dp[indx][maxWt]=max(take,notTake);

}
int knapsack(vector<int>weight,vector<int> value,int n,int maxWeight){
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
 
    //Tabulation method(Nottom-Up Dp)
    for(int w=weight[0];w<=maxWeight;w++)
        dp[0][w]=value[0];

    for(int indx=1;indx<n;indx++){
        for(int w=0;w<=maxWeight;w++){
            int notTake=dp[indx-1][w];
            int take=INT_MIN;
            if(weight[indx]<=w) 
             take=value[indx]+dp[indx-1][w-weight[indx]];

            dp[indx][w]=max(take,notTake);
        }
    }
      // For memoization :return fun(n-1,weight,maxWeight,value,dp);
      // for tabulation
      return dp[n-1][maxWeight];
}
