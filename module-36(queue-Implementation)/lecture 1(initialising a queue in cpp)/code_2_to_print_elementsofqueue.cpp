#include<iostream>
#include<queue>//includeing stl of queue to use the function of the library such as pop push top back
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
  return 0;
}