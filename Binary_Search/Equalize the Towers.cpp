class Solution {
    int check(vector<int>& heights, vector<int>& cost , int mid){
        int n = cost.size() ;
        int ans = 0 ;
        for(int i =0 ; i< n ; i++){
            int val = abs(heights[i] - mid) ;
            ans = ans + (val * cost[i]) ;
        }
        return ans ;
    }
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size() ;
        int l = *min_element(heights.begin() , heights.end()) ;
        int r = *max_element(heights.begin() , heights.end()) ;
        int ans = 0 ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            int cost1 = check(heights , cost , mid) ;
            int cost2 = check(heights , cost , mid+1) ;
            
            if(cost1 <= cost2){
                ans = cost1 ;
                r = mid - 1;
            }
            else
                l = mid + 1 ;
        }
        return ans ;
    }
};
