class Solution {
public:
    typedef pair<int,pair<int,int>> pel;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>ans;
        priority_queue<pel,vector<pel>,greater<pel>>pq;
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx = max(nums[i][0],mx);
            pq.push({nums[i][0],{i,0}});
        }
        int start = pq.top().first;
        int end = mx;
        while(true){
            int mn = pq.top().first;
            int row = pq.top().second.first;
            int column = pq.top().second.second;
            pq.pop();
            if(mx-mn < end-start){
                start = mn;
                end = mx;
            }
            if(column+1 >= nums[row].size()) break;
            mx = max(nums[row][column+1],mx);
            pq.push({nums[row][column+1],{row,column+1}});
           
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};