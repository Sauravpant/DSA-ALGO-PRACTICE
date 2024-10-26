/*
Problem: Given an array of positive integers and a target return true if there exists a subsequence/subset whose sum is equal to target.
A subsequnce is a contigious or non contigious part of an array in which the order of element is not violated.


*/
//  Classical Recursive approach : We can create any subsequnce by either picking or not picking up the element .Start from the last index , If we pick up
//the element we will move to index-1 with target reduced by that index value and if we do not pick up the element we will move to index-1 with same target
//Return the OR of pick and not pick as if any of the choice leads the target to 0 we have the dubsequence.If at any instant the target is reduced to 0,
//return true;

#include<bits/stdc++.h>
using namespace std;

bool isSubseq(int indx,int target,vector<int>&arr){
    if(target==0)  return true;
    if(indx==0) return(arr[indx]==target);

    bool pick=isSubseq(indx-1,target-arr[indx],arr);
    bool notPick=isSubseq(indx-1,target,arr);
    return pick || notPick;
}

//Memoization Solution
bool isSubseq(int indx,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)  return true;
    if(indx==0) return(arr[indx]==target);

    if(dp[indx][target]!=-1)   return dp[indx][target];

    bool pick=isSubseq(indx-1,target-arr[indx],arr,dp);
    bool notPick=isSubseq(indx-1,target,arr,dp);
    return dp[indx][target]=pick || notPick;
}
//Coversion to tabulation

bool isSubseq(int target,vector<int>&arr){
    
}