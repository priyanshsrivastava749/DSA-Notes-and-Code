#include<iostream>  //Stair Case 
using namespace std;

int stair(int x){
    if(x==1){
        return 1;
    }
    else if(x==0){
        return 1;
    }
    else{
        return stair(x-1)+stair(x-2);
    }
}






 int main(){
    int p;
    p=stair(10 );
    cout<<p;
 }