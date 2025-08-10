#include<iostream>
using namespace std;
class max_heap{
  public:
  int arr[50];
  int idx;
  max_heap(){
    idx = 1;
  }
  void push(int x){
    arr[idx]=x;
    idx++;
    //now theres a need for rearrangement;
    int i = idx-1;
    while(i != 1){
      int parent = i/2;
      if(arr[i]>arr[parent]){
        swap(arr[i],arr[parent]);
        i = parent;
      }
      else{
       break;
      }
    }
  }
  void pop(){
    idx = idx-1;
    arr[1] = arr [idx];
    //now theres a need of rearrangement 
    int i = 1;
    while(true){
      int left = 2*i;
      int right = 2*i + 1;
      if (left > idx-1){
        break;
      }
      if(right > idx-1){
        if(arr[i]<arr[left]){
          swap(arr[i],arr[left]);
          i = left;
          continue;
        }
        else break;
      }
      if(arr[left]>arr[right]){
        if(arr[i]<arr[left]){
          swap(arr[i],arr[left]);
          i = left;
        }
        else{
          break;
        }
      }
      else{
        if(arr[i]<arr[right]){
          swap(arr[i],arr[right]);
          i = right;
        }
        else{
          break;
        }
      }
    } 
  }
  void display(){
    for(int i=1;i<=idx-1;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  int top(){
    return arr[1];
  }
};
int main(){
  max_heap h;

  // Elements insert karo heap mein
  h.push(50);
  h.push(30);
  h.push(40);
  h.push(10);
  h.push(60);
  h.push(5);
  h.push(35);

  cout << "Heap after inserting elements:\n";
  h.display();  // Expected: Max heap view

  cout << "\nPopping all elements from heap:\n";
  while(h.idx > 1){
    cout << h.arr[1] << " ";
    h.pop();
  }

  return 0;
}