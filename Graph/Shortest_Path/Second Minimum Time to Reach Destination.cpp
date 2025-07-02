class Solution {
public:
    typedef pair<int ,int> p ;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int , list<int>> mpp ;
        for(int i =0 ; i < edges.size() ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;

            mpp[u].push_back(v) ;
            mpp[v].push_back(u) ;
        }
        vector<int> d1(n+1 , INT_MAX ) ;
        vector<int> d2(n+1 , INT_MAX) ;
        priority_queue<p , vector<p> , greater<p>> pq ;
        pq.push({0 ,1}) ;
        d1[1] = 0 ;

        while(!pq.empty()){
            auto [tp , node] = pq.top() ;
            pq.pop() ;

            if(node == n && d2[n] != INT_MAX )
                return d2[n] ;

            int div = tp / change ;
            if(div % 2 == 1)    
                tp = change * (div+1) ;

            for(auto it : mpp[node]){
                if(d1[it] > tp + time){
                    d2[it] = d1[it] ;
                    d1[it] = tp + time ;
                    pq.push({tp + time , it}) ;
                }
                else if(d2[it] > tp + time && d1[it] != tp + time){
                    d2[it] = time + tp ;
                    pq.push({time + tp , it}) ;
                }
            }    
        }
        return -1 ;
    }
};
