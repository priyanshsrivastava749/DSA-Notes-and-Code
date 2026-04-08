#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int dp[105][105];

// Helper function to calculate resulting color, passed vector by reference to avoid TLE
int g(const vector<int>& arr, int i, int j) {
    int result = 0;
    for (int k = i; k <= j; k++) {
        result = (result % 100 + arr[k] % 100) % 100;
    }
    return result;
}

// DP function
int function(const vector<int>& arr, int i, int j) {
    if (i >= j) { // Base case: single mixture or invalid
        return 0;
    }
    if (dp[i][j] != -1) { // Memoization check
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        ans = min(ans, function(arr, i, k) + function(arr, k + 1, j) + g(arr, i, k) * g(arr, k + 1, j));
    }
    return dp[i][j] = ans;
}

int main() {
    int n;
    // The problem statement says: "There will be a number of test cases in the input."
    // So we need to loop until EOF
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Initialize the DP table for every test case
        memset(dp, -1, sizeof(dp));
        
        cout << function(arr, 0, n - 1) << endl;
    }
    return 0;
}
