class Solution {
public:
    int f(vector<int>&arr,int n,vector<int> &dp){
        if(n == 0)return 0;
        if(dp[n] != -1)return dp[n];
        int curr = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            if(n >= arr[i]){ 
            int res = f(arr,n-arr[i],dp);
            if(res != INT_MAX)curr = min(curr,res + 1);
          }     
        }
        return dp[n] = curr;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1 , -1);
        return f(coins,amount,dp) != INT_MAX ? f(coins,amount,dp) : -1;
    }
};