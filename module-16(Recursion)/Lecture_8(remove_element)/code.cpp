#include<iostream>
using namespace std;

void removecharacter(string ans,string original,int idx){
    if(idx==original.length()){
        cout<<ans;
        return ;
    }
    char ch=original[idx];
   if(ch=='a'){return removecharacter(ans,original,idx+1);}
   else{removecharacter(ans+ch,original,idx+1);}
}









int main(){
    string str="Raghav Garg";
    removecharacter("",str,0);
}