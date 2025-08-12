class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        unordered_map<int,int> mp;
        for(int ele : digits){
            mp[ele]++;
        }
        for(int i=100;i<=999;i+=2){
            int x = i;
            int a = x % 10;//last digit
            x = x / 10;
            int b = x % 10;//second last digit
            x /= 10;
            int c = x % 10;
            if(mp.find(a) != mp.end()){
                //a found
                mp[a]--;
                if(mp[a]==0)mp.erase(a);
                if(mp.find(b) != mp.end()){
                    //b found in the map
                    mp[b]--;
                    if(mp[b]==0)mp.erase(b);
                    if(mp.find(c) != mp.end()){
                        //c is also existing
                        ans.push_back(i);
                    }
                    mp[b]++;
                }
                mp[a]++;
            }
        }
        return ans;
    }
};