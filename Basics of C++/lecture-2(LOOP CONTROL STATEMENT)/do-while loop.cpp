#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int a = 1;
    do{
        cout<<a<<"\n";
        a=a*2;
    }while(a<=n);
    return 0;
}
