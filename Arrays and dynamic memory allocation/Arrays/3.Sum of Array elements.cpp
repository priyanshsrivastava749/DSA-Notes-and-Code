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
    cout<<"\n";
    cout<<"The elements of the array are:"<<endl;
    for(int i =1;i<size;i++){
        cout<<arr[i]<<endl;
       
    }
    cout<<"\n";
    int sum=0;
    for(int i=1;i<size;i++){
        sum=sum+arr[i];
    }
    cout<<"\n";
    cout<<"The sum of input data  in the array is:"<<sum<<endl;
    
}
