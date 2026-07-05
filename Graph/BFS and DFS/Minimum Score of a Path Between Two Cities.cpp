class Solution {
public:
    typedef pair<int , int> p ;
    void dfs(int node ,vector<vector<p>> &adj , vector<int> &vis , int &mini){
        vis[node] = 1 ; 
        for(auto it : adj[node]){
            int v = it.first ; 
            int wt = it.second ; 
            mini = min(mini , wt) ; 
            if(!vis[v]){
                dfs(v , adj , vis , mini) ; 
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<p>> adj(n) ; 
        for(auto it : roads){
            int u = it[0] - 1 ;
            int v = it[1] - 1 ; 
            int wt = it[2] ; 

            adj[u].push_back({v , wt}) ; 
            adj[v].push_back({u , wt}) ; 
        }
        int mini =  INT_MAX ; 
        vector<int> vis(n , 0) ; 
        dfs(0 , adj, vis, mini) ; 
        return mini ;
    }
};
