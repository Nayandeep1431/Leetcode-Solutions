class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> st ;
        int n = color.size() ;
        
        for(int i =0 ; i< n ; i++){
            pair<int , int> p = {color[i] , radius[i]} ;
            if(st.empty()){
                st.push(p) ;
            }
            else{
                if(p == st.top())
                    st.pop() ;
                else
                    st.push(p) ;
            }
        }
        return st.size() ;
    }
};
