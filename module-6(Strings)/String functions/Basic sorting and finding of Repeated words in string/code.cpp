#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string s ="Akshat is a AI student and a DSA student as well";
    stringstream ss(s);
    vector<string>v;
    string temp;
    while(ss >> temp){
       v.push_back(temp); 

    }

    sort(v.begin(),v.end());
    int count=1;
    int maxCount=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i+1]){
             count++;
        }
        else count=1;
        maxCount=max(maxCount,count);
    }


    count =1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i+1]){
             count++;
        }
        else count=1;
        if(count==maxCount){
        cout<<v[i]<<" "<<maxCount<<endl;
    }
    }
    }