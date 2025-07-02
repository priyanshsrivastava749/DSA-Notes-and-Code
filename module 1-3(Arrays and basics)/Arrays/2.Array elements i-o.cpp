#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"The size of the array is:";
    cin>>size;
    int arr[size];
    for(int i =1;i<size;i++){
        cin>>arr[i];
       
    }
    for(int i =1;i<size;i++){
        cout<<arr[i];
       
    }
}
