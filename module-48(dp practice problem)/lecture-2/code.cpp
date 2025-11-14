#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

int f(int n){
    if(n==1) return 0;
    if(n == 2 || n == 3)return 1;
    int op1 = f(n-1);
    int op2 = (n % 2 == 0) ? f(n/2) : INT_MAX;
    int op3 = (n % 3 == 0) ? f(n/3) : INT_MAX;
    return 1 + min(op1,min(op2,op3));
}

using namespace std;
int main(){
    cout<<f(5);
    return 0;
}