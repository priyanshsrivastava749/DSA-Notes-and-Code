#include<iostream>
using namespace std;
int hanoi(int n,char a,char b,char c){
    if(n==0){return 0;}
    hanoi(n-1,a,c,b);
    cout<<a<<"->"<<b<<"\n";
    hanoi(n-1,b,c,a);
}



int main(){
    int n=2;
    hanoi(n,'A','B','C');
}