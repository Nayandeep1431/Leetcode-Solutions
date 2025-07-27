class Solution {
public:
    typedef long long ll ;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq ;
        
        vector<ll>prefix(n+1 , 0) ;
        int res = INT_MAX ;
        int j = 0 ;
        while(j < n){
            if(j == 0)
                prefix[j] = nums[j] ;
            else
                prefix[j] = prefix[j-1] + nums[j] ;

            if(prefix[j] >= k)
                res = min(res , j+1) ;

            while(!dq.empty() && prefix[j] - prefix[dq.front()] >= k){
                res = min(res , j - dq.front()) ;
                dq.pop_front() ;
            }            

            while(!dq.empty() && prefix[j] <= prefix[dq.back()])
                dq.pop_back() ;

            dq.push_back(j) ;
            j++ ;    
        }
        return res == INT_MAX ? -1 : res ;
    }   
};
