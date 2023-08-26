class MinStack {
    map<int,int> mp; // Stores in increasing order
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        mp[st.top()]--;
        if(mp[st.top()]==0)
            mp.erase(st.top());
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it=mp.begin();
        return it->first;
    }
};
