#include<iostream>
#include<stack>
#include<string>
using namespace std;
string solve(string v1,string v2,char ch){
  string s = "";
  s += v1;
  s.push_back(ch);
  s += v2;
  return s;
}
int main(){
  string s = "-+1/*+26483";
  stack<string>st;
  for(int i=s.length()-1; i>=0; i--){
    if(s[i]>=48 && s[i]<=57){
      st.push(to_string(s[i]-48));
    }
    else{
      string v1 = st.top();
      st.pop();
      string v2 = st.top();
      st.pop();
      char ch = s[i];
      string ans = solve(v1,v2,ch);
      st.push(ans);
    }
  }
  cout<<st.top();
  return 0;
}