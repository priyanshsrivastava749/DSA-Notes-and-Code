//leetcode 1944
class Solution {
  public:
      vector<int> canSeePersonsCount(vector<int>& arr) {
          int n = arr.size();
          vector<int> ans(n);
          stack<int> st;
          st.push(n-1);
          ans[n-1] = 0;
          for(int i=n-2;i>=0;i--){
              int count = 0;
              while(st.size()>0 && arr[i]>arr[st.top()]){
                  count++;
                  st.pop();  
              }
              if(st.size()>0){
                  count++;
                  ans[i] = count;
                  }
              else if(st.size()==0) ans[i] = count;
              st.push(i);
          }
          return ans;
      }
  };