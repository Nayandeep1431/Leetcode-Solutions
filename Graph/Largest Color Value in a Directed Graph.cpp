class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int , list<int>> adj ;
        int n = colors.length() ;
        vector<int> indegree(n , 0) ;
        for(int i =0 ; i< edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            adj[u].push_back(v) ;
            indegree[v]++ ;
        }

        queue<int> q ;
        vector<vector<int>>dp (n , vector<int> (26 , 0)) ;
        for(int i =0 ; i< n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
                dp[i][colors[i] - 'a'] = 1 ;
            }
        }

        int ans = 0 ;
        int cntNodes =0 ;
        while(!q.empty()){
            int front = q.front() ;
            q.pop() ;

            cntNodes++ ;
            ans = max(ans ,dp[front][colors[front] - 'a'] ) ;

            for(auto it : adj[front]){
                for(int i =0 ; i < 26 ; i++){
                    dp[it][i] = max(dp[it][i] , dp[front][i] + (colors[it] - 'a' == i)) ;
                }
                indegree[it]-- ;
                if(indegree[it] == 0)
                    q.push(it) ;
            }
        }
        if(cntNodes < n)
            return -1 ;
        else
            return ans ;    
    }
};
