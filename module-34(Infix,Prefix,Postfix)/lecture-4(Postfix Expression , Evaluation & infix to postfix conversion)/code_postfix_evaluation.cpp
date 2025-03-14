#include<iostream>
#include<string>
#include<stack>
using namespace std;
int priority(char ch){
  if(ch=='+'||ch=='-') return 1;
  else if(ch=='*'||ch=='/')return 2;
}
int eval(int v1,int v2,char ch){
  if(ch=='+') return v1+v2;
  else if(ch == '-')return v1-v2;
  else if(ch == '*') return v1*v2;
  else return v1/v2;
}
int main(){
  string s = "126+4*8/+3-";
  stack<int> val;
  for(int i=0;i<s.length();i++){
    if(s[i]>=48 && s[i]<=57){
      val.push(s[i]-48);
    }
    else{
        int v2 = val.top();
        val.pop();
        char ch = s[i];
        int v1 = val.top();
        val.pop();
        int ans = eval(v1,v2,ch);
        val.push(ans);
        }
    }
    cout<<val.top();
    return 0;
}