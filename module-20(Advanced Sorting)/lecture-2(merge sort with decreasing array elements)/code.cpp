#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a, vector<int> &b, vector<int> &res){
  int i = 0;//to iterate thorugh a
  int j = 0;//to iterate through b
  int k = 0;//to iterate through c
  while(i < a.size() && j < b.size()){
    if(a[i] >= b[j]){
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
  merge(a,b,v);
  return;
}
int main() {
    vector<int> v = {5, 2, 9, 1, 6, 3};

    merge_sort(v); // pura sort ho jayega

    cout << "Sorted Array: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}


