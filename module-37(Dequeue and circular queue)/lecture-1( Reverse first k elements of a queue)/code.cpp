//the following code consists the solution to the problem that is asking to reverse first k elements of the queue the stl of stack  can be used
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void display(queue<int> &q){
  for(int i=0;i<q.size();i++){
    int x = q.front();
    cout << x<<" ";
    q.pop();
    q.push(x);
  };
  cout<<endl;
  return;
}
void reverse_first_k(queue<int> &q,int k){
  stack<int> st;
  for(int i=1;i<k;i++){
    st.push(q.front());
    q.pop();
  }
  while(st.size()>0){
    q.push(st.top());
    st.pop();
  }
  for(int i=0; i<=q.size()-k; i++){
    int x = q.front();
    q.pop();
    q.push(x);
  }
  return;
}
int main(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  display(q);
  reverse_first_k(q,3);
  cout<<endl;
  display(q);
return 0;
}