class Solution {
public:
    vector<int> nextSmaller(vector<int> arr){
        int n = arr.size() ;
        vector<int> ans (n) ;
        stack<int> st ;

        for(int i =n-1 ; i >= 0 ; i--){
            int ele = arr[i] ;
            while(!st.empty() && arr[st.top()] >= ele)
                st.pop() ;
            ans[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ;    
        }
        return ans ;
    }    
    vector<int> prevSmaller(vector<int> arr){
        int n = arr.size() ;
        vector<int> ans (n) ;
        stack<int> st ;

        for(int i =0 ; i< n ; i++){
            int ele = arr[i] ;
            while(!st.empty() && arr[st.top()] >= ele)
                st.pop() ;
            ans[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ;    
        }
        return ans ;
    }

    int largestArea(vector<int> arr , int col){
        vector<int> next(col) , prev(col) ;
        next = nextSmaller(arr) ;
        prev = prevSmaller (arr) ;
        int maxi = INT_MIN ;

        for(int i =0 ; i< col ; i++){
            if(next[i] == -1)
                next[i] = col ;

            int l = arr[i] ;
            int b = next[i] - prev[i] - 1 ;
            int area = l*b ;
            maxi = max(maxi , area) ;    
        }
        return maxi ;
    }
int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> height(col, 0);
        int area = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            area = max(area, largestArea(height, col));
        }
        return area;
}
};
