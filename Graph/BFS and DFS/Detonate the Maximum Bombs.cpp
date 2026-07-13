class Solution {
public:
    typedef long long ll ; 
    void dfs(int node , vector<vector<int>> &adj , unordered_set<int> &st){
        st.insert(node) ; 
        for(auto it : adj[node]){
            if(st.find(it) == st.end())
                dfs(it , adj , st) ; 
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size() ;
        vector<vector<int>> adj(n) ; 
        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< n ; j++){
                ll x1 = bombs[i][0] ; 
                ll y1 = bombs[i][1] ; 
                ll r1 = bombs[i][2] ;

                ll x2 = bombs[j][0] ; 
                ll y2 = bombs[j][1] ; 
                ll y3 = bombs[j][2] ; 

                ll dist = (x2 - x1)* (x2 - x1) + (y2 - y1) * (y2 - y1) ; 

                if(ll(r1*r1) >= dist)
                    adj[i].push_back(j) ; 
            }
        }
        unordered_set<int> st ; 
        int maxi = 0 ; 
        for(int i =0 ; i< n; i++){
            dfs(i ,adj , st) ; 
            int cnt = st.size() ; 
            maxi = max(maxi , cnt) ;
            st.clear() ; 
        }
        return maxi ;
    }
};
