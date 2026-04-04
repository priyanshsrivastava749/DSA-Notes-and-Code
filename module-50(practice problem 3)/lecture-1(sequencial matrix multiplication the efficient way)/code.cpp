// Matrix Chain Multiplication (MCM) - Finding the minimum number of scalar
// multiplications needed to multiply a chain of matrices.
// Example: dimensions [10, 20, 30, 40, 50] represent 4 matrices:
//   A1(10x20), A2(20x30), A3(30x40), A4(40x50)
// We need to find the optimal parenthesization.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// arr = array of dimensions, i and j are indices into arr
// This computes MCM for matrices from index i to j-1
vector<vector<int>> dp(1000,vector<int>(1000,-1)); 
int minimum_multiplication(vector<int>& arr, int i, int j){
    // Base case: single matrix, no multiplication needed
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if (i + 1 == j){
        return dp[i][j] = 0;
    }
    int ans = INT_MAX;
    // Try every possible split point k between i and j
    for(int k = i + 1; k < j; k++){
        int cost = minimum_multiplication(arr, i, k) 
                 + minimum_multiplication(arr, k, j) 
                 + arr[i] * arr[k] * arr[j];
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int main(){
    int n;
    cout << "Enter number of dimensions: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter dimensions: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // n dimensions means n-1 matrices
    cout << "Minimum number of multiplications: " 
         << minimum_multiplication(arr, 0, n - 1) << endl;
    
    return 0;
}