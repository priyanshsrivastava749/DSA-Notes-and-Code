#include<iostream>
using namespace std;

int zig(int n){
    if(n==0){
        return 0;
    
    }
    cout<<n;
    zig(n-1);
    cout<<n;
     zig(n-1);
    cout<<n;
}
int main(){
    zig(4);

 }