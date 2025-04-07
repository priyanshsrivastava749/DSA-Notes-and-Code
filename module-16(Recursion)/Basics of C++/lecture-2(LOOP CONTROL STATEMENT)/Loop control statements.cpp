#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int a = 1;
    for(int i=0;i<=n;i++){
        cout<<a<<"\n";
        a=a*2;
    }
}

