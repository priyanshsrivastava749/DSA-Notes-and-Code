class Solution {
public:
    int minCostClimbingStairs(vector<int>& arr) {
        for(int i=2; i<arr.size(); i++){
            arr[i] += min(arr[i-1],arr[i-2]);
        }
        return min(arr[arr.size()-1],arr[arr.size()-2]);
    }
};