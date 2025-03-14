//first solution of the leetcode problem number https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int> st;
    stack<int> gt;
    MinStack() {
    //constructor of no use in this method    
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            gt.push(val);
        }
        // else if(val>gt.top()){
        //     st.push(val);
        //     gt.push(gt.top());
        // }
        // else {
        //     st.push(val);
        //     gt.push(val);
        // }
        else {
            st.push(val);
            gt.push(min(val,gt.top()));
        }
    } 
    void pop() {
        st.pop();
        gt.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return gt.top();
    }
};