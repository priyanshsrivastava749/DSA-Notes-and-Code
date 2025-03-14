class Solution {
  public:
      vector<int> maxSlidingWindow(vector<int>& v, int k) {
          int n = v.size();
          stack<int>st;
          vector<int>ngi(n);
          st.push(n-1);
          ngi[n-1] = n;
          for(int i = n-2; i>=0; i--){
              while(st.size()>0 && v[i]>v[st.top()]){
                  st.pop();
              }
              if(st.size()>0){
                  ngi[i] = st.top();
              }
              else if(st.size() == 0){
                  ngi[i] = n;
              }
              st.push(i);
          }
          vector<int>ans;
          int j = 0;
          for(int i=0; i<=n-k; i++){
              if(j<i) j = i; 
              int Max = v[i];
              while( j < i+k ){
                  Max = v[j];
                  if(ngi[j] > i+k)break;
                  j = ngi[j];
              }
             ans.push_back(Max);
          }
      return ans;
      }
  };