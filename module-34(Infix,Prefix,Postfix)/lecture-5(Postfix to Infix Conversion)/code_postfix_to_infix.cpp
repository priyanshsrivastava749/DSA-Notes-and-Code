#include<iostream>
#include<string>
#include<stack>
using namespace std;
string eval(string v1,string v2,char ch){
  string s = "";
  s += v1;
  s.push_back(ch);
  s += v2; 
  return s;
}
int main(){
  string s = "126+4*8/+3-";
  stack<string> val;
  for(int i=0;i<s.length();i++){
    if(s[i]>=48 && s[i]<=57){
      val.push(to_string(s[i]-48));
    }
    else{
        string v2 = val.top();
        val.pop();
        char ch = s[i];
        string v1 = val.top();
        val.pop();
        string ans = eval(v1,v2,ch);
        val.push(ans);
        }
    }
    cout<<val.top();
    return 0;
}