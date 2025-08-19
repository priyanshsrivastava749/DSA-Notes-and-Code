#include<iostream>
#include<vector>
using namespace std;
int count = 0;
int inversion(vector<int>a,vector<int>b){
  int count_temp = 0;
  int i = 0;
  int j = 0;
  int n1 = a.size();
  int n2 = b.size();
  while(i<n1 && j<n2){
    if(a[i]>b[j]){
      count_temp += (n1-i);
      j++;
    }
    else{
      i++;
    }
  }
  return count_temp;
}
void merge(vector<int> &a, vector<int> &b, vector<int> &res){
  int i = 0;//to iterate thorugh a
  int j = 0;//to iterate through b
  int k = 0;//to iterate through c
  while(i < a.size() && j < b.size()){
    if(a[i] < b[j]){
      res[k] = a[i];
      k++;
      i++;
    }
    else{
      //b[j] < a[i]
      res[k] = b[j];
      k++;
      j++;
    }
  }
  if(i >= a.size()){
    //see this
    while(j<b.size()){
      res[k] = b[j];
      k++;
      j++;
    }
  }
  else if(j >= b.size()){
    //see this
    while(i<a.size()){
      res[k] = a[i];
      i++;
      k++;
    }
  }
  return;
}
void merge_sort(vector<int>& v){
  int n = v.size();
  if(n == 1)return;
  int n1 = n/2;
  int n2 = n - n/2;

  vector<int> a(n1);
  vector<int> b(n2);

  for(int i=0; i<n1; i++){
    a[i] = v[i];
  }
  for(int i=0; i<n2; i++){
    b[i] = v[i+n1];
  }
  merge_sort(a);
  merge_sort(b);
  count += inversion(a,b);
  merge(a,b,v);
  return;
}

int main() {

  vector<int> v = {5,1,3,0,4,2,6};
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }

  cout<<endl;
  merge_sort(v);
  cout<<count;
  return 0;

}


