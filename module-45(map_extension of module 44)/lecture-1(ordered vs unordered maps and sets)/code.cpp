#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
  set<int>s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  //complexiety of finding or searching is log(n)
  for(int ele : s){
    cout<<ele<<" ";
  }
  cout<<endl;
  map<int,int> m;
  //ordered map me key is prioritised over value
  //same for string based key is saved in lexographical order
  m[1] = 30;
  m[2] = 20;
  m[3] = 10;
  for(auto ele : m){
    cout<<ele.first<<" "<<ele.second;
    cout<<endl;
  }
  return 0;
}