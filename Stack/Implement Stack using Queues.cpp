class MyStack {
public:
    queue<int> q1, q2;
    
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        if (q2.empty()) return -1;
        int ans = q2.front();
        q2.pop();
        return ans;
    }
    
    int top() {
        if (q2.empty()) return -1;
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};
