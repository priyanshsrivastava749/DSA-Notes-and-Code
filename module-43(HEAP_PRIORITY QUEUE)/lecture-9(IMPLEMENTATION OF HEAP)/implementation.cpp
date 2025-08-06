#include<iostream>
using namespace std;
class min_heap{
  public:
  int arr[50];
  int idx;
  min_heap(){
    idx = 1;
  }
  void push(int val){
    arr[idx] = val;
    int i = idx;
    idx++;
    while(i != 1){
      if(arr[i]<arr[i/2]){
        swap(arr[i],arr[i/2]);
      }
      else break;
      i = i/2;
    }
  }
  void pop(){
    idx--;
    arr[1] = arr[idx];
    int i = 1;
    while(true){
      int left = 2*i;
      int right = 2*i + 1;
      if(left > idx-1) break;
      if(right > idx-1){
        if(arr[left]<arr[i]){
          swap(arr[left],arr[i]);
        }
       break;
      }
      if(arr[left]<arr[right]){
        if(arr[i]>arr[left])
        {
          swap(arr[left],arr[i]);
          i = left;
        }
        else break;
      }
      else{
        if(arr[right]<arr[i]){
          swap(arr[right],arr[i]);
          i = right;
        }
        else break;
      }
    }
  }
  int top(){
    return arr[1];
  }
  void display(){
    for(int i=1;i<idx;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};
int main(){
  min_heap h;
   // Push test values
    h.push(50);
    h.display();
    h.push(30);
    h.display();
    h.push(40);
    h.display();
    h.push(10);
    h.display();
    h.push(20);
    h.display();
    h.push(60);
    h.display();

    // Expected min-heap order: 10, 20, 30, 40, 50, 60

    cout << "Popping elements in order:\n";
    while (h.idx > 1) {
        cout << h.top() << " "; // print current min
        h.pop();                // remove min
    }
  return 0;
}