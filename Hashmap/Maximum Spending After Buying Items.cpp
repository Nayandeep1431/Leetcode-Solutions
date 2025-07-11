class Solution {
public:
    typedef long long ll ;
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size() ;
        int n = values[0].size() ;

        ll ans = 0 ;
        priority_queue<int , vector<int> , greater<int>> pq ;
        for(int i=0 ; i< m ; i++){
            for(int j =0 ; j< n ; j++){
                pq.push(values[i][j]) ;
            }
        }
        ll days = 1;
        while(!pq.empty()){
            ll top = pq.top() ;
            pq.pop() ;

            ans += 1LL*(top * days) ;
            days++ ;
        }
        return ans ;
    }
};
