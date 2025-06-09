//code to sort k sorted array or vector
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  vector<int> arr = {10,9,8,7,4,70,60,50};
  int k = 4;
  vector<int> ans;
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0;i<arr.size();i++){
    pq.push(arr[i]);
    if(pq.size()>k){
      ans.push_back(pq.top());
      pq.pop();
    }
  }
  while(pq.size()>0){
    ans.push_back(pq.top());
    pq.pop();
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}