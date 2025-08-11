class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            s.insert(arr[i]);
        }
        for(int ele : s){
            int freq = mp[ele];
            for(auto mp_ele : mp){
                int freq2 = mp_ele.second;
                if(mp_ele.first == ele) continue;
                if(freq == freq2) return false;
            }
        }
     return true;
    }
};