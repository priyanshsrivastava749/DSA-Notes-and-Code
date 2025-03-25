#include<iostream>
using namespace std;
int main(){
  int arr[]={5,4,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  for(int i=0;i<n-1;i++){//i is to represent the number of passes and j is to represent the number of operations in each pass 
    for(int j=0;j<n-1-i;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}