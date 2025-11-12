class Solution {
public:
     int helper(int sr,int sc,int er,int ec,vector<vector<int>>& dp,vector<vector<int>>& arr){
        if(sr > er || sc > ec)return 0;
        if(arr[sr][sc] == 1)return 0;
        if(sr == er && sc == ec) return 1;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        int rightway = helper(sr,sc+1,er,ec,dp,arr);
        int downway = helper(sr+1,sc,er,ec,dp,arr);
        return dp[sr][sc] = rightway + downway;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp,arr);
    }
};