class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ; 
        if(n <= 2)
            return n ;

        int maxi = *max_element(nums.begin() , nums.end()) ; 
        int ind = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            if((maxi & (1 << i)) != 0){
                ind = i ; 
                break ; 
            }
        }    

        return pow(2 , ind+1) ;
    }
};
