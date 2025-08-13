class Solution {
public:
    int rev(int n){
        int rev = 0;
        while(n != 0){
            rev = rev*10 + n%10;
            n /= 10;
        }
     return rev;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i] - rev(nums[i])) != mp.end()){
                count = count % 1000000007;
                count += mp[nums[i] - rev(nums[i])];
                mp[nums[i] - rev(nums[i])]++;
            }
            else mp[nums[i] - rev(nums[i])]++;
        }      
        return count % 1000000007;
    }
};