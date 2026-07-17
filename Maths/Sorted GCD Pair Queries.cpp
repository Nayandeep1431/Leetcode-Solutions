class Solution {
public:
    typedef long long ll ; 
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size() ; 
        int maxi = *max_element(nums.begin() , nums.end()) ; 

        vector<int> freq(maxi+1 , 0) ; 
        for(int i =0 ; i < n ; i++){
            int val = nums[i] ; 

            for(int j = 1 ; j*j <= val ; j++){
                if(val % j == 0){
                    freq[j]++ ; 
                    if(val / j != j)
                        freq[val/j]++ ; 
                }        
            }
        }
        vector<ll> cnt(maxi+1 , 0) ; 
        for(int i = maxi ; i>=1 ; i--){
            ll val = freq[i] ; 
            cnt[i] =( val * (val -1)) / 2 ;

            for(int j = i*2 ; j <= maxi ; j += i ){
                cnt[i] -= cnt[j] ; 
            }
        }
        vector<ll> prefix(maxi+1 ,0) ; 
        for(int i =1 ; i<= maxi; i++){
            prefix[i] = prefix[i-1] + cnt[i] ; 
        }

        vector<int> ans ; 
        for(ll i : queries){
            int l = 1 , h = maxi , temp = 1 ; 
            while(l <= h){
                int mid = l + (h-l) / 2 ;
                if(prefix[mid] > i){
                    temp = mid ; 
                    h = mid - 1 ;
                }
                else
                    l = mid + 1 ; 
            }
            ans.push_back(temp) ; 
        }
        return ans ; 
    }
};
