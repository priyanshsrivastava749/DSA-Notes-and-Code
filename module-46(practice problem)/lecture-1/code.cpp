class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
       int n = nums.size();
       vector<int> pre(n,0);
       pre[0] = nums[0];
       for(int i=1; i<n; i++){
            pre[i] = nums[i] + pre[i-1];
       }
       unordered_map<int,int> mp;
       int count=0;
       for(int i=0; i<n; i++){
        if(pre[i]==target) count++;
        int x = pre[i] - target;
        if(mp.find(x) != mp.end()){
            count += mp[x];
        }
        mp[pre[i]]++;
       }
       return count;
    }
};