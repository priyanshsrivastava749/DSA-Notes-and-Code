// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         for(int i=0;i<=nums.size()-2;i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]+nums[j]==target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// unordered_map method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mp;
       vector<int>ans;
       for(int i=0; i<nums.size(); i++){
        if(mp.find(target-nums[i])!=mp.end()){
            //if found then this block would be hit
            ans.push_back(mp[target-nums[i]]);
            ans.push_back(i);
        }
        else{
            mp[nums[i]]=i;
        }
       }
       return ans;
    }
};