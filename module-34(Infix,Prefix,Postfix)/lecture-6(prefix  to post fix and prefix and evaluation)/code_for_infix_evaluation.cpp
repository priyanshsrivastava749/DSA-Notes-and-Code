#include<iostream>
#include<stack>
#include<string>
using namespace std;
int solve(int v1,int v2,char ch){
  if(ch=='+') return v1 + v2;
  else if(ch == '-')return v1 - v2;
  else if(ch == '*')return v1 * v2;
  else return v1/v2;
}
int main(){
  string s = "-+1/*+26483";
  stack<int>st;
  for(int i=s.length()-1; i>=0; i--){
    if(s[i]>=48 && s[i]<=57){
      st.push(s[i]-48);
    }
    else{
      int v1 = st.top();
      st.pop();
      int v2 = st.top();
      st.pop();
      char ch = s[i];
      int ans = solve(v1,v2,ch);
      st.push(ans);
    }
  }
  cout<<st.top();
  return 0;
}