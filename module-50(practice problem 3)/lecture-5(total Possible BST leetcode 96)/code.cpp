class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==0 or n==1)return 1;
        if(n == 2)return 2;
        if(dp[n] != -1)return dp[n];
        int sum = 0;
        for(int k = 1; k <= n ; k++){
            sum += f(k-1,dp) * f(n-k,dp);
        }
        return dp[n] = sum;
    }
    int numTrees(int n) {
        vector<int>dp(21,-1);
        return f(n,dp);
    }
};

// 96. Unique Binary Search Trees
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

// Example 1:


// Input: n = 3
// Output: 5
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 19
 
// Seen this question in a real interview before?
// 1/6
// Yes
// No
// Accepted
// 8,64,695/1.4M
// Acceptance Rate
// 63.6%
// Topics
// icon
// Companies
// Similar Questions
// Discussion (98)

// Choose a type









// Read more








// Read more

 
















 




// Read more














// Read more














// Read more
// Copyright © 2026 LeetCode. All rights reserved.