#include<iostream>
using namespace std;
int pivot_finder(int arr[],int si,int li){
  int pivot_element = arr[si];
  int count = 0;
  for(int i=si+1; i<=li; i++){
    if(pivot_element>arr[i]) count++;
  }
  int pivot_index = count + si;
  swap(arr[count+si],arr[si]);
  int i = si;
  int j = li;
  while(i < pivot_index && j > pivot_index){
    if(arr[i]>pivot_element && arr[j]<pivot_element){
      swap(arr[i],arr[j]);
      i++;
      j--;
    }
    else if(arr[i]>pivot_element && arr[j]>pivot_element){
      j--;
    }
    else{//arr[i]<pivot_element && arr[j]<pivot_element
      i++;
    }
  }
  return pivot_index;
}
void quick_sort(int arr[],int si,int li){
  if(si>=li) return;
  //find pivot index for further sorting using reccursion
  int pi = pivot_finder(arr,si,li); //see here we got our first element of the array to be at its correct position
  quick_sort(arr,si,pi-1);
  quick_sort(arr,pi+1,li);
}
int main(){
  int arr[] = {5,1,8,2,7,6,3,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}