class Solution {
public:
    void dfs(unordered_map<int ,list<int>> &mpp , vector<int> &res , vector<int> &store , int curr , int par , string &labels){
        char ch = labels[curr] ;
        int before = store[ch - 'a'] ;

        store[ch-'a']++ ;
        for(auto it : mpp[curr]){
            if(it == par)
                continue ;
            dfs(mpp , res , store ,it , curr, labels) ;    
        }
        int after = store[ch - 'a'] ;
        res[curr] = after - before ;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int , list<int>> mpp ;
        for(int i =0 ; i< edges.size() ;i++ ){
            int u = edges[i][0] ;
            int v = edges[i][1] ;

            mpp[u].push_back(v) ;
            mpp[v].push_back(u) ;
        }
        vector<int> res(n , 0) ;
        vector<int> store(26 , 0) ;

        dfs(mpp , res , store , 0 , -1 , labels) ;
        return res ;
    }
};
