//check if the given array could be divided into two sub arrays where the each array have the same sum of their elements
#include<iostream>
using namespace std;
int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  int n = sizeof(arr)/sizeof(arr[0]);
  //formation of prefix sum 
  bool flag = false;
  for(int i=1; i<n; i++){
    arr[i] += arr[i-1];
  }
  //Now check for x if it exists
  for(int i=0;i<n-1;i++){
    if(2*arr[i] == arr[n-1]){
      flag = true;
      break;
    }
  }
  if(flag == true){
    cout<<"yes the given array could be partitioned into two sum array having same sum of their elements. ";
  }
  else{
    cout<<"sorry it can't be devided into two sub arrays having same number of elements. ";
  }
  return 0;
}