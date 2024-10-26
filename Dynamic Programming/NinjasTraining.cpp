//2D dynamic Programming
//Problem : Ninjas Training






#include<bits/stdc++.h>
using namespace std;

// Using recursion 
//The base case will be if we reach at day 0 with any task done we will find the maximum of the remianing 2 task and return it to the calling function else we add the respective point and 
//call the function again to recursively solve the problem with day-1 amd stating a TASK is done
int compute(int day,int last,vector<vector<int>>&points){
    if(day==0){
        int maxm=0;
        for( int task = 0; task<3; task++){
            if(task!=last)
            maxm=max(maxm,points[0][task]);
        }
        return maxm;
    }
    int maxm=0;
    for(int task=0;task<3;task++){
        if(task!=last){
        int point=points[day][task]+compute(day-1,task,points);
        maxm=max(maxm,point);
        }
         
    }
    return maxm;
}


int ninjaTraining(int n,vector<vector<int>>&points){
    return compute(n-1,3,points);
}

// Memoization and conversion to the Dynamic Programming solution:
//The concept behind memoization is that if we have overlapping subproblems ,instead of making the recursion deep we can store the values of the recursion calls from beginning so that if any 
//overlapping subproblem is encountered we can just return the stored value instead of again making the recursion call and increasing the depth of the recursion.it is a top down DP approach .
//Since it is a 2D DP problem ,the days can be from 0 to n-1(0 based indexing) and for any day we have 4 choices 0,1,2,3 which indicate that the respective tasks are already done and we cant do 
// that task again, task=3 means that we are starting initially and no task have been done. for eg compute(2,1,points) means that we have tp find the maximum points that we can earn till day 2
//starting from 0 and task 1 has been already done right before this that is at index 3 

int compute(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    if(day==0){
        int maxm=0;
        for( int task = 0; task<3; task++){
            if(task!=last)
            maxm=max(maxm,points[0][task]);
        }
        return maxm;
    }
    if(dp[day][last]!=-1)
    return dp[day][last];
    int maxm=0;
    for(int task=0;task<3;task++){
        if(task!=last){
        int point=points[day][task]+compute(day-1,task,points,dp);
        maxm=max(maxm,point);
        }
         
    }
    return dp[day][last]=maxm;
}
int ninjaTraining(int n,vector<vector<int>>&points){
    vector<vector<int>> dp(n,vector<int>(4,-1));  // A 2D dp array initialized with -1
    return compute(n-1,3,points,dp);
}



//Conversion to Tabulation :Bottom up DP
int ninjaTraining(int n,vector<vector<int>>&points){
    vector<vector<int>> dp(n,vector<int>(4,-1));  // A 2D dp array initialized with -1
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],points[0][1],points[0][2]);

    for(int day=1;day<n;day++){
        for(int last=0;last<=3;last++){
            dp[day][last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
                
            }
        }
    }
    return dp[n-1][3];
}

//Space optimization: Since for calculating the points for any day we only require the points of day-1 with tasks 0,1,2,3 we need not to carry an entire array for this instead we can carry an 
//array of size 4 and initially store the base vallues in it ,Now for any day we create a temporary array and compute the values for thet day in that array and at the end we just update our 
//main array with this temporary array as we require only the values of previous state.

// Final Optimized DP solution with TC=O(N*4)*3 and SC=0(1) (4 size array is a constant space so O(1))
int ninjaTraining(int n,vector<vector<int>>&points){
    vector<int> prev(n,-1); 
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],points[0][1],points[0][2]);

    for(int day=1;day<n;day++){
        vector<int> temp(4,-1);
        for(int last=0;last<=3;last++){
            temp[last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    int point=points[day][task]+prev[task];
                    temp[last]=max(temp[last],point);
                }
                
            }
        }
        prev=temp;
    }
    return prev[3];
}