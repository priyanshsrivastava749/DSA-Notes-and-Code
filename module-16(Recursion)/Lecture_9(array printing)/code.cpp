#include<iostream>
using namespace std;
int print(int n ,int j,int arr[]){
    if(j==n) return n+1;
   
    cout<<arr[j];
    print(n,j+1,arr);
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<print(4,0,arr);


}