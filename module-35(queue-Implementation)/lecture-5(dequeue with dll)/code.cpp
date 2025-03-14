#include<iostream>
using namespace std;
class node{
  public:
  int val;
  node* next;
  node* prev;
  node(int val){
    this->val = val;
    next = NULL;
    node* prev =NULL;
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
  void push_back(int val){
    if(size == 0){
    node* temp = new node(val);
    f = temp;
    b = temp;
    size++;
    }
    else{
      node* temp = new node(val);
      b -> next = temp;
      temp -> prev = b;
      b = temp;
      size++;
    }
  }
  void push_front(int val){
    if(size == 0){
    node* temp = new node(val);
    f = temp;
    b = temp;
    size++;
    }
    else{
      node* temp = new node(val);
      f -> prev = temp;
      temp -> next = f;
      f = temp;
      size++;
    }
  }
  void pop_back(){
    if(size==0){
      cout<<"QUEUE IS ALREADY EMPTY!";
    }
    else{
      node *temp = b;
      b = b->prev;
      delete temp;
      b->next = NULL;
      size--;
    }
  };
  void pop_front(){
    if(size==0){
      cout<<"QUEUE IS ALREADY EMPTY!";
    }
    else{
      node *temp = f;
      f = f->next;
      delete temp;
      f->prev = NULL;
      size--;
    }
  };
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
  void length(){
    cout<<size<<endl;
  }
};
int main(){
  queue q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);
  q.display();
  q.pop_back();
  q.display();
  q.push_front(0);
  q.push_front(-1);
  q.push_front(-2);
  q.display();
  q.pop_front();
  q.display();
  q.front();
  q.back();
  q.length();
  return 0;
}