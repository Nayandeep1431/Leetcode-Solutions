class Solution {
public:
    typedef vector<int> V ; 
    typedef pair<int, int> p ; 

    static bool cmp(vector<int> &a , vector<int> &b){
        return a[2] < b[2] ;
    }

    int parent(vector<int> &par , int u){
        if(par[u] == u)
            return u ;
        else return par[u] = parent(par , par[u]) ;     
    }

    void unionRank(int u , int v , V &par , V &rank){
        u = parent(par ,u) ; 
        v = parent(par , v) ; 
        if(rank[u] < rank[v])
            par[u] = v ;
        else if(rank[v] < rank[u])
            par[v] = u;
        else{
            rank[u]++ ;
            par[v] = u ;
        }        
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size() ; 
        vector<bool> ans(m) ;
        V par(n , 0) ;
        V rank(n , 0)  ; 
        for(int i =0 ; i< n ; i++){
            par[i] = i ; 
            rank[i] = 0 ;
        } 
        sort(edgeList.begin() , edgeList.end() , cmp) ; 
        for(int i = 0 ; i< queries.size() ; i++){
            queries[i].push_back(i) ; 
        }
        sort(queries.begin() , queries.end() , cmp) ; 
        int i =0 , j = 0 ; 
        while(j < m){
            int r = queries[j][0] , c = queries[j][1] , wt = queries[j][2] , ind = queries[j][3] ; 
            while(i < edgeList.size() && edgeList[i][2] < wt){
                unionRank(edgeList[i][0] , edgeList[i][1] , par , rank) ; 
                i++ ;
            }
            if(parent(par , r) != parent(par , c))
                ans[ind] = false ;
            else
                ans[ind] = true ;    
            j++ ;    
        }
        return ans ;
    }
};
