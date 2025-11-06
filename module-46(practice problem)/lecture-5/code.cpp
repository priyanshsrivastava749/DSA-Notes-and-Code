class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> modified(arr.size(),0);
        for(int i=0; i<arr.size(); i++){
            modified[i] = (((arr[i] % k) + k) % k) ;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[modified[i]]++; 
        }
        for(auto ele : mp){
            int num = ele.first;
            int freq = ele.second;
            if(num == 0 && freq % 2 != 0) return false;
            if(mp.find(k-num) != mp.end()){
                if(mp[k-num] == mp[num]){
                    mp[k-num] = 0;
                    mp[num] = 0;
                }
            }
            }
        for(auto ele : mp){
            int freq = ele.second;
            if(freq != 0 && ele.first != 0) return false;
        }
        return true;
    }
};