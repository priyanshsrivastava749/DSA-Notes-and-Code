class Solution {
public:
    long long f(int n,int k ,int t,vector<vector<long long>> & dp){
        const long long MOD = 1000000007;
        if(n == 0 && t == 0)return 1;
        if(n == 0 && t != 0)return 0;
        if(dp[n][t] != -1)return dp[n][t];
        long long sum = 0;
        for(int i=1; i<=k; i++){
            if(t >= i ){
                sum += f(n-1,k,t-i,dp);
                sum %= MOD;
            }
        }
        return dp[n][t] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,-1));
        return (int)f(n,k,target,dp);
    }
};