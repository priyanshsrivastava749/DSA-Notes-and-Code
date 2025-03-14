//method-2 most optimised method of complexiety O(1) space and O(1) https://leetcode.com/problems/min-stack/
class MinStack {
  public:
      stack<long long> st;
      long long min;
      MinStack() {
          min = LLONG_MAX;
      }
      
      void push(int val) {
         long long x = (long long)val;
         if(st.size()==0){
          st.push(x);
          min = x;
         }
         else if(x>min){
          st.push(x);
         }
         else{
          st.push(2*x-min); 
          min = x;
         }
      }
      
      void pop() {
         if(st.top()<min){
          min = 2*min - st.top();
         }
         st.pop();       
      }
      
      int top() {
          if(st.top()<min) return (int)min;
          else return (int)st.top();      
      }
      
      int getMin() {
          return (int)min;
      }
  };