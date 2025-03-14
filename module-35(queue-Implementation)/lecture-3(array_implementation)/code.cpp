#include<iostream>
using namespace std;
class Queue{
  public:
  int f;
  int b;
  int arr[5];
  Queue(){
    f = 0;
    b = 0;
  }
  void push(int val){
    if(b==5){
      cout<<"Queue is full!";
      return;
    }
    else{
    arr[b] = val;
    b++;
    }
  }
  void pop(){
    if(b - f == 0){
      cout<<"Queue is empty!";
      return;
    }
    else f++;
  }
  void front(){
    if(b-f == 0){
      cout<<"Queue is empty!";
      return;
    }
    else {
      cout<<arr[f];
      return;
    }
  }
  void size(){
    cout<< b-f;
  }
  void display(){
    for(int i=f;i<b;i++){
      cout<<arr[i]<<" ";
    }
  }
};
int main(){
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.display();
  q.pop();
  cout<<endl;
  q.display();
  return 0;
}