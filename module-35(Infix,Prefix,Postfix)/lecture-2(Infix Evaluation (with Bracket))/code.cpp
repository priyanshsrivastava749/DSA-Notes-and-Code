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
  string s = "1+(2+6)*4/8-3";
  stack<int> val;
  stack<char> op;
  for(int i=0;i<s.length();i++){
    if(s[i]>=48 && s[i]<=57){
      val.push(s[i]-48);
    }
    else{
      if(op.size()==0){
        op.push(s[i]);
      }
      else if(s[i]=='('||op.top()=='(') op.push(s[i]);
      else if(op.size()>0 && s[i]==')'){
        while(op.top()!='('){
          int v2 = val.top();
          val.pop();
          int v1 = val.top();
          val.pop();
          char ch = op.top();
          op.pop();
          int ans = eval(v1,v2,ch);
          val.push(ans);
        }
        op.pop();
      }
      else if(priority(op.top())<priority(s[i])) op.push(s[i]);
      else{
        while(op.size()>0 && priority(op.top())>=priority(s[i])){
          int v2 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        int v1 = val.top();
        val.pop();
        int ans = eval(v1,v2,ch);
        val.push(ans);
        }
        op.push(s[i]);
      }
    }
  }
  while(op.size()>0){
        int v2 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        int v1 = val.top();
        val.pop();
        int ans = eval(v1,v2,ch);
        val.push(ans);
  }
  cout<<val.top();
  return 0;
}