class Solution {
public:
typedef long long ll; 
    vector<int> par , rank ; 
    int parent(int u){
        if(par[u] == u)
            return u ;
        else
            return par[u] = parent(par[u]) ;     
    }

    void rankUnion(int u , int v){
        u = parent(u) ; 
        v = parent(v) ; 

        if(u == v)
            return ;
        if(rank[u] < rank[v])
            par[u] = v ;
        else if(rank[v] < rank[u])
            par[v] = u ;
        else{
            par[u] = v ;
            rank[v]++ ;
        }            
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size() ; 
        vector<vector<int>> adj(n) ; 
        for(int i =0 ; i< edges.size() ; i++){
            int u = edges[i][0] ; 
            int v = edges[i][1] ;

            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }

        par.resize(n) ; 
        rank.resize(n , 0) ; 
        for(int i =0 ; i< n; i++)
            par[i] = i ;

        vector<int> active(n , false) ; 

        map<int , vector<int>> val ; 
        for(int i =0 ; i< n; i++){
            val[vals[i]].push_back(i) ; 
        }  

        int res = n ; 

        for(auto &it : val){
            vector<int> nodes = it.second ; 
            
            for(int v : nodes){
                for(int u : adj[v]){
                    if(active[u])
                        rankUnion(u , v) ; 
                }
                active[v] = true ;
            }

            vector<int> tp ; 
            for(int v : nodes)
                tp.push_back(parent(v)) ; 

            sort(tp.begin() , tp.end()) ; 
            int s = tp.size() ;

            for(int i= 0 ; i< s ; i++){
                ll cnt = 0 ; 
                int curr = tp[i] ; 
                while(i < s && tp[i] == curr){
                    cnt++ ; 
                    i++ ;
                }
                i--;
                res += (cnt * (cnt-1)) / 2 ;
            }    
        }  
        return res ;
    }
};
