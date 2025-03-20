#include<iostream>
using namespace std;
void subs(string ans,string original){
    if(original==""){cout<<ans<<"\n";
        return; }
    char ch=original[0];
    subs(ans,original.substr(1));
    subs(ans+ch,original.substr(1));
}








int main(){
    string str="abc";
    subs("",str);
}