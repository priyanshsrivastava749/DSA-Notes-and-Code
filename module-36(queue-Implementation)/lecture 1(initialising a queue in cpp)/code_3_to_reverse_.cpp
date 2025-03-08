#include<iostream>
#include<stack>
#include<queue>//includeing stl of queue to use the function of the library such as pop push top back
using namespace std;
int main(){
  ///to print the element of the stack in reversed manner
  queue<int> q;
  stack<int> st;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  while(!q.empty()){
    int x = q.front();
      st.push(x);
      q.pop();
  }
  while(st.size()>0){
    cout<<st.top()<<" ";
    q.push(st.top());
    st.pop();
  }
  return 0;
}