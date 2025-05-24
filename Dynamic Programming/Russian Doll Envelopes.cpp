class Solution {
    bool check(vector<int> &a , vector<int> &b){
        if(a[0] > b[0] && a[1] > b[1])
            return true ;
        else
            return false ;    
    }
    int solve(vector<vector<int>> &arr , int n){
        // vector<vector<int>> dp(n+1 , vector<int>(n+1 ,0)) ;
         vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        for(int i = n-1 ; i>= 0 ; i--){
            for(int prev = i-1 ; prev>= -1 ; prev--){
                int nottake = next[prev+1] ;
                int take = 0 ;
                if(prev == -1 || check(arr[i] , arr[prev]))
                    take = 1 + next[i+1] ;

                curr[prev+1] = max(take , nottake) ;    
            }
            next = curr ;
        }
        return curr[0] ;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // int n = envelopes.size() ;
        // sort(envelopes.begin() , envelopes.end()) ;
        // return solve(envelopes , n) ;


        // Sort by width ASC and height DESC (for same width)
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1]; // decreasing height if same width
            return a[0] < b[0];
        });

        // Extract heights only
        vector<int> heights;
        for(auto &env : envelopes) {
            heights.push_back(env[1]);
        }

        // Find LIS on heights
        vector<int> dp;
        for(int h : heights){
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if(it == dp.end())
                dp.push_back(h);
            else
                *it = h;
        }
        return dp.size();
    }
};

