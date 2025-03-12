//the following code contain the solution of the leetcode problem number 950 https://leetcode.com/problems/reveal-cards-in-increasing-order/
class Solution {
  public:
      vector<int> deckRevealedIncreasing(vector<int>& v) {
          sort(v.begin(),v.end());
          queue<int>q;
          for(int i=0;i<v.size();i++){
              q.push(i);
          }
          vector<int>ans(v.size());
          int j=0;
          while(q.size()>0){
              ans[q.front()]=v[j];
              q.pop();
              j++;
              if(q.size()==0) break;
              q.push(q.front());
              q.pop();
          }
      return ans;
      }
  };