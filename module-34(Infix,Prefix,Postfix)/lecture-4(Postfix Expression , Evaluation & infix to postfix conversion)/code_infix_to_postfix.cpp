#include<iostream>
#include<string>
#include<stack>
using namespace std;
int priority(char ch){
  if(ch=='+'||ch=='-') return 1;
  else if(ch=='*'||ch=='/')return 2;
}
string eval(string v1,string v2,char ch){
  string s = "";
  s += v1;
  s += v2;
  s.push_back(ch);
  return s;
}
int main(){
  string s = "1+(2+6)*4/8-3";
  stack<string> val;
  stack<char> op;
  for(int i=0;i<s.length();i++){
    if(s[i]>=48 && s[i]<=57){
      val.push(to_string(s[i]-48));
    }
    else{
      if(op.size()==0){
        op.push(s[i]);
      }
      else if(s[i]=='('||op.top()=='(') op.push(s[i]);
      else if(op.size()>0 && s[i]==')'){
        while(op.top()!='('){
          string v2 = val.top();
          val.pop();
          string v1 = val.top();
          val.pop();
          char ch = op.top();
          op.pop();
          string ans = eval(v1,v2,ch);
          val.push(ans);
        }
        op.pop();
      }
      else if(priority(op.top())<priority(s[i])) op.push(s[i]);
      else{
        while(op.size()>0 && priority(op.top())>=priority(s[i])){
        string v2 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        string v1 = val.top();
        val.pop();
        string ans = eval(v1,v2,ch);
        val.push(ans);
        }
        op.push(s[i]);
      }
    }
  }
  while(op.size()>0){
        string v2 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        string v1 = val.top();
        val.pop();
        string ans = eval(v1,v2,ch);
        val.push(ans);
  }
  cout<<val.top();
  return 0;
}