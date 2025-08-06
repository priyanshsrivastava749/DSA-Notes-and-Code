#include<iostream>
using namespace std;
int main(){
    int a[]={0,1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<"The size of the array is:"<<size<<endl;
    cout<<&a<<endl; // address of the array
    cout<<&a[0]<<endl;
    cout<<&a[1]<<endl;
    cout<<&a[2]<<endl;
}
