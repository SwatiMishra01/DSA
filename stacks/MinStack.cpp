----------------------------------------
  APPROSCH 1
-----------------------------------------

class MinStack {
public:
stack<pair<int,int>>st;
    MinStack() { 
    }
    
    void push(int val) {   
        if(st.empty())  st.push({val,val});
        else
        st.push({val,min(val,st.top().second)});
    }


    
    void pop() {
        st.pop();
    }


    
    int top() {
        return st.top().first;
    }


    int getMin() {
       return  st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
T.C=O(1)
S.C=O(2 N)

-------------------------------------------------
  APPROACH 2-> modifying values using equation
 -------------------------------------------------
  class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        //if stack is empty mini=val
        if(st.empty()){
        mini=val;
        st.push(val);
        }
        
        //if new push value is small update mini
        else if(val<mini){
            st.push(2LL*val -mini); //modified one pushed into stack
            mini=val; //it will be represent as top element if asked
        }

        else
        st.push(val);
    }
    
    void pop() {
        if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
    }
    
    int top() {
        if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
T.C=O(1)
S.C=O(N)
