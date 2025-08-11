class Solution {
public:
    int reverse_the_number(int num){
        int rev = 0;
        while(num!=0){
            rev = rev*10 + num%10;
            num = num / 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            int rev = reverse_the_number(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }
};