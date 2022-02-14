class MinStack {
public:
    MinStack() 
        :minimum(INT_MAX)
    {
        
        
    }
    
    void push(int val) {
        if(val<minimum)
        {
            minimum = val;
        }
        s.push(make_pair(val, minimum));
    }
    
    void pop() {
        s.pop();
        if(s.empty())
            minimum = INT_MAX;
        else
            minimum = s.top().second;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return minimum;
    }
    private:
    int minimum;
    stack<pair<int, int>> s;
};
