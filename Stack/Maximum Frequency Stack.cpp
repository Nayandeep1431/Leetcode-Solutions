class FreqStack {
public:
    FreqStack() {
        
    }
    
    unordered_map<int , stack<int>> st ; 
    unordered_map<int , int> freq ; 
    int maxi = 0 ; 
    void push(int val) {
        freq[val]++ ; 
        maxi = max(maxi , freq[val]) ; 
        int num = freq[val] ; 
        st[num].push(val) ; 
    }
    
    int pop() {
        int val = st[maxi].top() ; 
        st[maxi].pop() ; 
        freq[val]-- ;
        maxi = st[maxi].empty() ? maxi - 1 : maxi ; 
        return val ;
    }
};
