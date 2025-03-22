#include<iostream>
using namespace std;
int kGram(int n,int k){
    if(n==1) return 0;
    if(k%2==0){
        int ans=kGram(n-1,k/2);
        if(ans==0) return 1;
        else{ return 0;}
        //even
    }

    else{
        int ans=kGram(n-1,k/2+1);
        return ans;
    }
}



int main(){
    int p;
    p=kGram(3,2);
    cout<<p;

}