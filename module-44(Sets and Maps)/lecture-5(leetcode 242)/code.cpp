// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         if(s==t){return true;}
//         else return false;
//     }
// };
//priority queue method 2 using 2 priority queue
// class Solution{
//     public:
//       bool isAnagram(string s,string t){
//         if(s.length()!=t.length())return false;
//         unordered_map<char,int> mp1;//for s
//         unordered_map<char,int> mp2;//for t
//         for(int i=0;i<s.length();i++){
//             mp1[s[i]]++;
//         }
//         for(int i=0;i<t.length();i++){
//             mp2[t[i]]++;
//         }
//         for(auto pr : mp1){
//             char ch = pr.first;
//             char freq = pr.second;
//             if(mp2.find(ch)!=mp2.end()){
//                 //element is present
//                 if(mp2[ch] != mp1[ch]){
//                     return false;
//                 }
//             }
//             else return false;
//         }
//         return true;
//       }
// };
//method 3 using single maps
class Solution{
    public:
      bool isAnagram(string s,string t){
        if(s.length()!=t.length())return false;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch = t[i];
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
                if(mp[ch]==0){
                    mp.erase(ch);
                }
            }
            else return false;
        }
        return true;
      }
};