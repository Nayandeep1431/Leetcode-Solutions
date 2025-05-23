class Solution {
public:
typedef long long ll ;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size() ;
        ll sum =0 ;
        ll count =0 ;
        ll loss =LONG_MAX ;

        for(int i =0 ; i< n ; i++){
            ll num = nums[i] ;
            if((num ^ k )> num){
                sum += (num ^ k) ;
                count++ ;
            }
            else
                sum += num ;
            loss = min(loss , abs(num - (num^ k))) ;
              
        }
        if(count % 2 == 0)
            return sum ;
        else
            return (sum - loss) ;    
    }
};
