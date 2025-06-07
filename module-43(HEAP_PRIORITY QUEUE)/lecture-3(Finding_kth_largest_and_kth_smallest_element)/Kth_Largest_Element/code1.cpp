//this code is all about finding kth Largest element in the array in () complexiety
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  vector<int> v = {10,20,-4,6,1,24,105,118};
  int k = 4;//find 4th Largest element
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0;i<v.size();i++){
    pq.push(v[i]);
    if(pq.size()>k)pq.pop();
  }
  cout<<pq.top();
  return 0;
}
