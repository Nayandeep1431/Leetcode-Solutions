class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0} ;

        unordered_map<int , list<int>> adj ;
        vector<int> indegree(n ,0) ;
        for(int i =0 ; i< edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;

            indegree[u]++ ;
            indegree[v]++ ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }    

        queue<int>q ;
        for(int i =0 ; i< n ; i++){
            if(indegree[i] == 1)
                q.push(i) ;
        }

        vector<int> ans ;
        while(n > 2){
            int size = q.size() ;
            n-= size ;
            while(size--){
                int front = q.front() ;
                q.pop() ;

                for(auto it : adj[front]){
                    indegree[it]-- ;
                    if(indegree[it] == 1)
                        q.push(it) ;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()) ;
            q.pop() ;
        }
        return ans ;
    }

};
