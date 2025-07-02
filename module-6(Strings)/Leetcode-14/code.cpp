#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last =strs[n-1] ;
        string s="";
        for(int i=0;i<(min(first.size(),last.size()));i++){
               if(first[i]==last[i]){
                s+=first[i];
               }
               else return s;

               

        }
        return s;
    }
};