#include<iostream>
using namespace std;
class node{
  public:
  int val;
  node* next;
  node(int val){
    this->val = val;
    next = NULL;
  }
};
class queue{ public:
  node* f;
  node* b;
  int size;
  queue(){
    f = NULL;
    b = NULL;
    size = 0;
  }
  void push(int val){
    if(size == 0){
    node* temp = new node(val);
    f = temp;
    b = temp;
    size++;
    }
    else{
      node* temp = new node(val);
      b -> next = temp;
      b = temp;
      size++;
    }
  }
  void pop(){
    if(size==0){
      cout<<"QUEUE IS ALREADY EMPTY!";
    }
    else{
      node *temp = f;
      f = f->next;
      delete temp;
      size--;
    }
  }
  void front(){
    cout<<f->val;
    cout<<endl;}
  void back(){
    cout<<b->val;
    cout<<endl;
  }
  void display(){
    node* temp = f;
    while(temp){
      cout << temp -> val<<" ";
      temp = temp -> next;
    }
    cout<<endl;
  }
};
int main(){
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.display();
  q.pop();
  q.display();
  return 0;
}