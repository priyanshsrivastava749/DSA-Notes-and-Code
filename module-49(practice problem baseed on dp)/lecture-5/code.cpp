#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k,l,m;
    cin>>k>>l>>m;
    vector<bool>dp(1000005, 0);
    dp[1] = true;
    dp[k] = true;
    dp[l] = true;
    for(int i=2; i<=1000000; i++){
        if(i == k || i == l)continue;
        dp[i] = !(dp[i-1] && ((i-k >= 1) ? dp[i-k] : 1) && ((i-l >= 1) ? dp[i-l] : 1));
    }
    for(int i=0;i<m; i++){
        int n;
        cin>>n;
        if(dp[n] == true){
        cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
    return 0;
}

//the code can be submitted here https://www.spoj.com/problems/MCOINS/ 