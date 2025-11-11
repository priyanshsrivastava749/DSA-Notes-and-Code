class Solution {
public:
    int helper(int sr,int sc,int er,int ec,vector<vector<int>>& dp){
        if(sr == er && sc == ec) return 1;
        if(sr > er || sc > ec)return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        int rightway = helper(sr,sc+1,er,ec,dp);
        int downway = helper(sr+1,sc,er,ec,dp);
        return dp[sr][sc] = rightway + downway;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp);
    }
};