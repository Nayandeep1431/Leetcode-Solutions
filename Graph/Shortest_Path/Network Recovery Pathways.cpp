class Solution {
public:
    typedef pair<int ,int> p ;
bool dijakstra(vector<vector<p>>& adj, int mid, long long k, int n){

    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> pq;

    vector<long long> dist(n, LLONG_MAX);
    dist[0]=0;
    pq.push({0,0});
    
    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();

        if(d>dist[node])
            continue;

        for(auto [next,wt]:adj[node]){
            if(wt<mid)
                continue;

            if(d+wt<dist[next]){
                dist[next]=d+wt;
                pq.push({dist[next],next});
            }
        }
    }

    return dist[n-1]<=k;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size() ; 
        vector<vector<p>> adj(n) ; 
        int maxi = 0 ;
        for(int i =0 ; i< edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            int wt = edges[i][2] ; 

            if(!online[u] || !online[v])
                continue ;
            adj[u].push_back({v , wt}) ; 
            maxi = max(maxi ,wt ) ;     
        }
        int l = 0 , r = maxi ; 
        int res = -1 ; 
        while(l <=r ){
            int mid = l + (r-l)/2 ;
            if(dijakstra(adj , mid ,k ,n)){
                res = mid ; 
                l = mid + 1 ;
            }
            else
                r = mid - 1 ;
        }
        return res ; 
    }
};
