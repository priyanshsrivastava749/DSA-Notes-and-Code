class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length() != str2.length()) return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0; i<str1.length(); i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        for(auto ele : mp1){
            if(mp2.find(ele.first) == mp2.end()) return false;
        }
        unordered_map<char,int> h1,h2;
        for(auto ele : mp1){
            h1[ele.second]++;
        }
        for(auto ele : mp2){
            h2[ele.second]++;
        }
        for(auto ele : h1){
            if(h2.find(ele.first)==h2.end())return false;
            if(h1[ele.first] != h2[ele.first])return false;
        }
        return true;
    }
};