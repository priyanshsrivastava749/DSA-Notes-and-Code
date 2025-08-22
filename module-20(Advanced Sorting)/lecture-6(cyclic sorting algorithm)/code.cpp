#include<iostream>
using namespace std;
void display(int arr[],int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }  
  cout<<endl;
}
void cyclic_sort(int arr[],int n){
    
    int i = 0;
    while(i<n){
    int correct_index = arr[i] - 1; 
    if(correct_index == i) i++;
    else swap(arr[i],arr[correct_index]);
  }
}
int main(){
  int arr[] = {5,1,2,4,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  display(arr,n);
  cyclic_sort(arr,n);
  display(arr,n);
  return 0;
}