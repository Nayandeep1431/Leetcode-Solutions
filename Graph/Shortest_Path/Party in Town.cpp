class Solution {
  public:
    void dfs(int node , int parent , int dist ,vector<vector<int>> &adj , vector<int> &dis){
        dis[node] = dist ; 
        for(int it : adj[node]){
            if(it != parent)
                dfs(it , node , dist+1 , adj , dis) ; 
        }
    }
    
    int partyHouse(int N, vector<vector<int>> &adj) {
        // code here
        vector<int> dist1(N+1 , -1) ;  
        dfs(1 , 0 , 0 , adj , dist1 ) ; 
        
        int A = 1 ; 
        for(int i =1 ; i <= N ; i++){
            if(dist1[i] > dist1[A])
                A = i ;
        }
        
        vector<int> distA (N+1 , -1) ; 
        dfs(A , 0 , 0 , adj , distA) ; 
        
        int B = A ;
        for(int i =1 ; i<=N ; i++){
            if(distA[i] > distA[B])
                B = i ;
        }
        
        vector<int> distB(N+1 , -1) ; 
        dfs(B , 0 , 0 , adj , distB) ; 
        
        int maxi = 0 , mini = INT_MAX ; 
        for(int i =1 ; i<= N ; i++){
            maxi = max(distA[i] , distB[i]) ; 
            mini = min(mini , maxi) ;
        }
        return mini ;
    }
};
