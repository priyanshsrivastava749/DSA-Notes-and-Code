#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int main(){
  int arr[] = {19,12,23,8,16};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int> visited_or_not(n,0);
  int x = 0;
  for(int i=0;i<n;i++){
    int mn = INT_MAX;
    int mindx = -1;
    //finding the minimum element
    for(int j = 0 ;j<n;j++){
      if(visited_or_not[j] == 1) continue;
      if(mn > arr[j]){
       mn = min(mn,arr[j]);
       mindx = j;
      } 
    }
    arr[mindx] = x;
    visited_or_not[mindx] = 1;
    x++;
  }
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}