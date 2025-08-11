#include<iostream>
#include <unordered_map>
#include<string>
using namespace std;
int main(){
  unordered_map<string,int> mp;
  pair<string,int>p1;
  pair<string,int>p2;
  pair<string,int>p3;
  p1.first = "priyansh";
  p1.second = 77;
  p2.first = "akshat";
  p2.second = 37;
  p3.first = "aayansh";
  p3.second = 33;
  mp.insert(p1); 
  mp.insert(p2);
  mp.insert(p3);
  mp["Lokesh"] = 55;
  // for(pair<string,int> pr : mp){
  //   cout<<pr.first<<" "<<pr.second<<endl;
  // }
  for(auto pr : mp){
    cout<<pr.first<<" "<<pr.second<<endl;
  }
  cout<<endl;
  cout<<mp.size();
  cout<<endl;
  mp.erase("priyansh");
  for(auto pr : mp){
    cout<<pr.first<<" "<<pr.second<<endl;
  }
  cout<<mp.size()<<endl;
  return 0;
}
