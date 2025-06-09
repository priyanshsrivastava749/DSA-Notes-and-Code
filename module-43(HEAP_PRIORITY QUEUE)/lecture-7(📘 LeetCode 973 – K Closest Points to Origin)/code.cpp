class Solution {
  public:
      typedef pair<int,vector<int>> pi;
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<pi> pq;
          for(vector<int> v:points){
              int x = v[0];
              int y = v[1];
              int distance = x*x + y*y;
              pq.push({distance,v});
              if(pq.size()>k){
                  pq.pop();
              }
          }
          vector<vector<int>> ans;
          while(pq.size()>0){
              ans.push_back(pq.top().second);
              pq.pop();
          }
          return ans;
      }
  };