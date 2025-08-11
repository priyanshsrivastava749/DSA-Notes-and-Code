#include<iostream>
#include <unordered_set>
using namespace std;
int main(){
  unordered_set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);
  int target = 5;
  if(s.find(target)!=s.end()){
    cout<<"Element Found!"<<endl;
  }
  else{
    cout<<"Element Not Found!";
  }
  for(int ele:s){
    cout<<ele<<" ";
  }
  return 0;
}
