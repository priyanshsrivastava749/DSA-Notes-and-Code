//the following code is the solution to the leetcode problem number 239 https://leetcode.com/problems/sliding-window-maximum/
class solution{
public:
vector<int> maxSlidingWindow(vector<int>& v, int k){
  if(k==1) return v;
  int n = v.size();
  vector<int> ans;
  deque<int> dq;
  for(int i=0;i<n;i++){
      while(dq.size()>0 && v[i]>=v[dq.back()]) dq.pop_back();
      if(dq.size()==0 || v[dq.back()]>v[i]) dq.push_back(i);
      while(dq.front()<i+1-k) dq.pop_front();
      if(i>=k-1){
          ans.push_back(v[dq.front()]);
      }
  }
return ans;
  }
}