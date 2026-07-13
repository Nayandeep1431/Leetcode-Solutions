class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int , int>> st ; 
    int next(int price) {
        int val = 1 ; 
        while(!st.empty() && st.top().first <= price){
            val += st.top().second ; 
            st.pop() ;
        }
        st.push({price , val}) ; 
        return val ; 
    }
};
