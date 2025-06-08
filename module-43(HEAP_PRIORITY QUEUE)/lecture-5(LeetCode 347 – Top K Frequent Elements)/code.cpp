class Solution {
  public:
      vector<int> topKFrequent(vector<int>& arr, int k) {
          typedef pair<int,int> p;
          unordered_map<int,int> mp;
          for(int ele:arr){
              mp[ele]++;
          }
          priority_queue<p,vector<p>,greater<p>> pq;
          //now we have to fill this priority queue 
          for(auto x:mp){
              int value = x.first;
              int frequency = x.second;
              pair<int,int> p = {frequency,value};
              pq.push(p);
              if(pq.size()>k){
                  pq.pop();
              }
          }
          vector<int>ans;
          while(pq.size()>0){
              int val = pq.top().second;
              ans.push_back(val);
              pq.pop();
          }
       return ans;
      }
  };