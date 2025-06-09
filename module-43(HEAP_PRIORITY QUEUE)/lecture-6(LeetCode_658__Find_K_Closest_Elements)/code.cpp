class Solution {
  public:
      typedef pair<int,int> pi;
      vector<int> findClosestElements(vector<int>& arr, int k, int x) {
          priority_queue<pi> pq;
          for(int val: arr){
              int distance = abs(val-x);
              pq.push({distance,val});
              if(pq.size()>k){
                  pq.pop();
              }
          }
          vector<int>ans;
          while(pq.size()>0){
              ans.push_back(pq.top().second);
              pq.pop();
          }
          sort(ans.begin(),ans.end());
          return ans;
      }
  };