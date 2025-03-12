//the following code contains the solution of the leetcode problem number 649 https://leetcode.com/problems/dota2-senate/
class Solution {
  public:
      string predictPartyVictory(string s) {
          queue<int>q;
          queue<int>r;
          queue<int>d;
          for(int i=0; i<s.size(); i++){
              q.push(i);
              if(s[i]=='R'){
                  r.push(i);
              }
              else d.push(i);
          }
          while(q.size()>=1){
              while(s[q.front()]=='X') q.pop();
              if(s[q.front()] == 'R'){
                  if(d.size()==0){
                      return "Radiant";
                  }
                  else{
                      s[d.front()]='X';
                      d.pop();
                      q.push(q.front());
                      q.pop();
                      r.push(r.front());
                      r.pop();
                  }
              }
              else{//traversal ka time per jab D aaya ho to
                  if(r.size()==0){
                      return "Dire";
                  }
                  else{
                      s[r.front()]='X';
                      r.pop();
                      q.push(q.front());
                      q.pop();
                      d.push(d.front());
                      d.pop();
                  }
              }
          }
          if(s[q.front()]=='R') return "Radiant";
          else return "Dire";
      }
  };