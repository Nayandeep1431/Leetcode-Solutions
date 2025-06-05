class Solution {
    int dfs(int node, int dest, unordered_map<int, list<int>> &adj, vector<int> &dp) {
        if (node == dest)
            return 1;
        if (dp[node] != -1)
            return dp[node];

        int totalPaths = 0;
        for (int neighbor : adj[node]) {
            totalPaths += dfs(neighbor, dest, adj, dp);
        }

        return dp[node] = totalPaths;
    }
    
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        unordered_map<int , list<int>> adj ;
        for(int i =0 ; i< edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            adj[u].push_back(v) ;
        }
        int cnt = 0 ;
        vector<int> dp(V , -1) ;
        return dfs(src, dest, adj, dp); ;
            }
};
