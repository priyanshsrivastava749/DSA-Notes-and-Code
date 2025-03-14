class Solution {
  public:
      int countStudents(vector<int>& students, vector<int>& sandwiches) {
          queue <int> q;
          int i = 0;
          while(i <= students.size()-1){
            q.push(students[i]);
            i++;
          }
          //we have successfully made a queue
          int j = 0;
          int count = 0;
          while(j <= sandwiches.size()-1 && count <= q.size()){
              if( q.front() == sandwiches[j] ){
                  count = 0;
                  q.pop();
                  j++;
              }
              else{
                  count++;
                  int x = q.front();
                  q.pop();
                  q.push(x);
              }
          }
          return q.size();
      }
  };