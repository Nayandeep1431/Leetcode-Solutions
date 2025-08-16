class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int , list<int>> mpp ;
        if(roads.size() == 0)
            return 0 ;

        for(int i =0 ; i< roads.size() ; i++){
            int u = roads[i][0] ;
            int v = roads[i][1] ;

            mpp[u].push_back(v) ;
            mpp[v].push_back(u) ;
        }
        int maxi = 0 ;
        for(int i =0 ; i < n ; i++){
            for(int j =i+1 ; j< n ; j++){
           multiset<int> st ;
           bool connect = false ;

            for(auto it : mpp[i]){
                st.insert(it) ;
                if(it == j)
                    connect = true ;
            }    

            for(auto it : mpp[j])
                st.insert(it) ;

            int val = st.size() ;
            if(connect )
                val-- ;
            maxi = max(maxi , val) ;        
            }
        }    
        return maxi ;
    }
};
