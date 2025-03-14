#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  for(int i=0; i<q.size(); i++){
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    q.push(x);
  }
  int x = q.size();
  for(int i=0;i<x;i++){
    if(i%2==0){
      q.pop();
    }
    else{
      int y = q.front();
      q.pop();
      q.push(y);
    }
  }
  cout<<endl;
  for(int i=0; i<q.size(); i++){
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    q.push(x);
  }
  return 0;
}