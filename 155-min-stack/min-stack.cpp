class MinStack {
public:
    vector<int> st;
    vector<int> mn;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);
    if (mn.size()==0 || value <= mn[mn.size()-1]) {
        mn.push_back(value);
    }
    }
    
    void pop() {
        if(st[st.size()-1]==mn[mn.size()-1]) mn.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        return mn[mn.size()-1];   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */