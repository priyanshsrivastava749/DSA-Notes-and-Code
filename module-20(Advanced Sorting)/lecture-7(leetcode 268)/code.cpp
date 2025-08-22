class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //method 1 using extra space actually o(n)
        int n = nums.size();
        vector<bool>flag_vector(n+1,false);
        for(int i=0;i<n;i++){
            flag_vector[nums[i]] = true;
        }
        for(int i=0;i<=n;i++){
            if(flag_vector[i] == false)return i;
        }
        return 100;
    }
};