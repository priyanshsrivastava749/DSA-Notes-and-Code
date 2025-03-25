#include<iostream>
using namespace std;
int main(){
  int arr[] = {6,1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=1;i<n;i++){
    int j=i;
    while(j>=1 && arr[j]<arr[j-1]){
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
  }
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}