class Solution{
    int stock(int index,int buy,int capacity,vector<int>&prices,vector<vector<vector<int>>> &dp,int n){
        if(capacity==0 || index==n)
        return 0;

        if(dp[index][buy][capacity]!=-1)   return dp[index][buy][capacity];

        long profit=0;
        if(buy){
            return max(-prices[index]+stock(index+1,0,capacity,prices,dp,n),stock(index+1,1,capacity,prices,dp,n));

        }

        return max(prices[index]+stock(index+1,1,capacity-1,prices,dp,n),stock(index+1,buy,capacity,prices,dp,n));
    }
    public:
    int () {
 

};