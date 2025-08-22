#include<iostream>
using namespace std;

int pivot_finder(int arr[],int si,int li){
  int pivot_element = arr[(si + li) / 2];
  int count = 0;
  for(int i=si; i<=li; i++){
    if(arr[i] == pivot_element)continue;
    if(arr[i]<pivot_element) count++;
  }
  //now place the pivot to its right position
  int pivot_index = count + si; 
  swap(arr[(si + li) / 2],arr[pivot_index]);
  pivot_element = arr[pivot_index];
  int i = si;
  int j = li;
  while(i<pivot_index && j>pivot_index){
    if(arr[i]>pivot_element && arr[j]<pivot_element){
      swap(arr[i],arr[j]);
    }
    else if(arr[i]>pivot_element && arr[j]>pivot_element){
      j--;
    }
    else i++;
  }
  return pivot_index;
}

int  k_th_smallest(int arr[],int si,int li,int k){
  int pi = pivot_finder(arr,si,li);
  if(pi+1 == k)return arr[pi];
  else if(k > pi)return k_th_smallest(arr,pi+1,li,k);
  else return k_th_smallest(arr,si,pi-1,k);
}
int main(){
    int arr[] = {5,1,8,2,7,6,3,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"The 5th Smallest Element is:"<<k_th_smallest(arr,0,n-1,5);
  return 0;
}