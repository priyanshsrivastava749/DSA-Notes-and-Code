class Solution {
  public:
      struct comp {
      bool operator()(pair<int, int>& a, pair<int, int>& b) {
          if (a.first == b.first)
              return a.second < b.second; // prefer higher value if same frequency
          return a.first > b.first;       // min-heap based on frequency
      }
      };
  
      vector<int> frequencySort(vector<int>& nums) {
          typedef pair<int,int> p;
          unordered_map<int,int>mp;
          //maping done now every value has a frequency
          for(int num:nums){
              mp[num]++;
          }
          vector<int>ans;
          priority_queue<p,vector<p>,comp> pq;
          for(auto x:mp){
              int value = x.first;
              int frequency = x.second;
              pq.push({frequency,value});
          }
          while(pq.size()>0){
              int value = pq.top().second;
              int frequency = pq.top().first;
              for(int i=0;i<frequency;i++){
                  ans.push_back(value);
              }
              pq.pop();
          }
  
          return ans;
      }
  };