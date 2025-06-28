class Solution {
public:
    int dfs(unordered_map<int, list<int>> &mpp ,int node , int par , vector<bool> &has){
        int time = 0 ;
        for(auto it : mpp[node]){
            if(it == par)
                continue ;

            int t = dfs(mpp , it, node ,has);
            if(t > 0 || has[it])
                time += t + 2 ;    
        }
        return time ;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, list<int>> mpp ;
        for(int i =0 ; i< edges.size() ; i++ ){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            mpp[u].push_back(v) ;
            mpp[v].push_back(u) ;
        }
        return dfs(mpp ,0 , -1 , hasApple) ;
    }
};
