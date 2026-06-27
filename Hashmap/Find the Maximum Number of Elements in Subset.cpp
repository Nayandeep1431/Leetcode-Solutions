class Solution {
public:
    typedef long long ll ;
    int maximumLength(vector<int>& nums) {
        int n = nums.size() ; 
        map<ll , int> mpp ; 
        for(int i =0 ; i< n ; i++)
            mpp[1LL*nums[i]] ++ ;
        int one = mpp[1] ; 
        one = (one % 2 ) ? one : one - 1 ;

        int maxi = 1 ; 
        for(auto it : mpp){
            if(it.first == 1)
                continue ;
            if(it.second == 1)
                continue ;
            int cnt = 1 ;
            ll x = it.first ; 
            while(mpp.find(x*x) != mpp.end()){
                cnt += 2 ;
                if(mpp[x*x] > 1)
                    x = x*x ;
                else
                    break ;    
            }  
            maxi = max(maxi , cnt) ;  
        }    
        maxi =max(maxi , one) ;
        return maxi ;
    }
};
