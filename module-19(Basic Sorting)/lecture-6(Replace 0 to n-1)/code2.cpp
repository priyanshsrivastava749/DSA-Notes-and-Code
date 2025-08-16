#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
  int arr[] = {19,12,23,8,16};
  int n = sizeof(arr) / sizeof(arr[0]);
  unordered_map<int,int>mp;
  vector<int>v;
  for(int i=0;i<n;i++){
    v.push_back(arr[i]);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    mp[v[i]] = i;
  }
  for(int i=0;i<n;i++){
    arr[i] = mp[arr[i]];
  }
  for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}