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
    int x;
    cout<<"Enter the element you want to searh";
    cin>>x;
    bool flag=false;
    for(int i=0;i<size;i++){
        if(arr[i]==x){
            flag=true;
            break;
        }
        else{
           flag=false;
        }
    }
    if(flag==true){
        cout<<"The element is present in the array"<<endl;
    }
    else{
        cout<<"The element is not present in the array"<<endl;
    }
    cout<<"\n";
}
