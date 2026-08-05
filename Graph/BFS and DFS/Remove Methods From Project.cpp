class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n) ; 
        vector<int> vis(n , false) ; 
        vector<int> indeg(n , 0) ;
        for(auto it : invocations){
            int u = it[0] ; 
            int v = it[1] ; 
            adj[u].push_back(v) ; 
            indeg[v]++ ;
        }
        queue<int> q ; 
        q.push(k) ; 
        vis[k] = true ; 
        while(!q.empty()){
            int top = q.front() ; 
            q.pop() ; 

            for(int it : adj[top]){
                indeg[it]-- ; 
                if(!vis[it]){
                    vis[it] = true ; 
                    q.push(it) ; 
                }
            }
        }
        vector<int> ans ; 
        bool flag = false ; 
        for(int i =0 ; i< n ; i++){
            if(vis[i] == true && indeg[i] > 0){
                flag = true ; 
                break ; 
            }

            if(!vis[i])
                ans.push_back(i) ; 
        }
        if(flag){
            vector<int> res ; 
            for(int i = 0 ; i< n ; i++)
                res.push_back(i) ; 
            return res ;    
        }
        return ans ;
    }
};
