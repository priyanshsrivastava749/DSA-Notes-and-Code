#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
  int arr[] = {5, 4, 2, 100, 150, 200, 300};
  int n = sizeof(arr)/sizeof(arr[0]);
  float kmin=(float)INT_MIN;
  float kmax=(float)INT_MAX;
  bool flag = true;
  for(int i=0;i<n-1;i++){
    if(arr[i]>=arr[i+1]){
      //condition to find the min value of k 
      kmin = max(kmin,(float)((arr[i]+arr[i+1])/2.0));
    }
    else{
      kmax = min(kmax,(float)((arr[i]+arr[i+1])/2.0));
    }
    if(kmin>kmax){
      flag = false;
      break;
    }
  }
  if(flag == false){
    cout<<"No limit exist!";
  }
  else{
    cout<<"["<<(int)kmin+1<<","<<kmax<<"]";
  }
  return 0;
}