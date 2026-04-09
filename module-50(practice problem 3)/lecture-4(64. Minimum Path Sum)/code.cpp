class Solution {
public:
    int m, n;
    
    // Helper function for Top-Down DP (Memoization)
    // It returns the minimum path sum from (i, j) to the destination (m-1, n-1)
    int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        // Base Case 1: Out of bounds
        // If we move out of the grid, return a very large value (1e9) so it won't be picked by min()
        if(i > m-1 || j > n-1) return 1e9;
        
        // Base Case 2: Destination reached
        // If we reached the bottom-right cell, return its value
        if(i == m-1 && j == n-1) return grid[i][j];
        
        // Memoization Check
        // If we have already computed the answer for cell (i, j), just return it directly
        if(dp[i][j] != -1) return dp[i][j];
        
        // Transitions:
        // Try going both Right (j+1) and Down (i+1), take the minimum of their path sums
        // Add the current cell's value and store it in dp[i][j] before returning
        return dp[i][j] = grid[i][j] + min(f(grid, i+1, j, dp), f(grid, i, j+1, dp));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        // Assign the grid dimensions to global variables
        m = grid.size();
        n = grid[0].size();
        
        // Create a 2D DP matrix to store evaluated states, initialized with -1.
        // Array size is 200x200 max as per problem constraints (1 <= m, n <= 200)
        vector<vector<int>> dp(200, vector<int>(200, -1));
        
        // Start moving from the top-left cell at (0, 0)
        return f(grid, 0, 0, dp);
    }
};