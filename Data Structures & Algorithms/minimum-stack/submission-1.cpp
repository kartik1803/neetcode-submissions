class MinStack {
public:

long long mini;
    stack<long long> st;

    MinStack() {
         mini = INT_MAX;
    }
    
    void push(int value) {
          if(st.empty()) {
            mini = value;
            st.push(value);
        }
        else if(value >= mini) {
            st.push(value);
        }
        else {
            long long encoded = 2LL * value - mini;
            st.push(encoded);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) {
            return;
        }

        if(st.top() >= mini) {
            st.pop();
        }
        else {
            long long oldmini = 2LL * mini - st.top();
            mini = oldmini;
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) {
            return -1;
        }

        if(st.top() >= mini) {
            return (int)st.top();
        }

        return (int)mini;
        
    }
    
    int getMin() {
        return mini;
        
    }
};
