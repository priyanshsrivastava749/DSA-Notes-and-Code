#include<iostream>
#include<queue>//includeing stl of queue to use the function of the library such as pop push top back
using namespace std;
int main(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  cout<<q.front();
  return 0;
}