class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //we ve got nums as in [4,3,2,7,8,2,3,1]
        int i = 0;
        int len = nums.size();
        while(i < len){
            int correct_index = nums[i] - 1;
            if(nums[i] == nums[correct_index]){
                i++;
            }
            else{
                swap(nums[i],nums[correct_index]);
            }
        }
        vector<int>ans;
        for(int i=0; i<len; i++){
            if(i+1!=nums[i])ans.push_back(i+1);
        }
        return ans;
    }
};