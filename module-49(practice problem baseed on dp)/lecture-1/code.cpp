#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>memo;
vector<int>getdigits (int n){
    vector<int>v;
    while(n > 0){
        int ld = n % 10;
        if(ld != 0)v.push_back(ld);
        n = n / 10;
    }
    return v;
}
int f(int n){
    if(n == 0) return 0; 
    vector<int> dp = getdigits(n);
    if(memo[n] != -1) return memo[n];
    int result = INT_MAX;
    for(int i=0; i<dp.size() ; i++){
        result =  min(result,1 + f(n - dp[i]));
    }
    return memo[n] = result;
}
int main(){
    int n;
    cin>>n;
    memo.clear();
    memo.resize(n + 1,-1);
    cout<<f(n);
    return 0;
}