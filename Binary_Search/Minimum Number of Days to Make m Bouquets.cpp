class Solution {
public:
    typedef long long ll ;
    bool poss(vector<int> &arr, int m , int k , int mid){
        int n = arr.size() ;
        int days = 0  , cnt = 0 ;
        for(int i =0 ; i< n ; i++){
            if(arr[i] <= mid)
                cnt++ ;
            else{
                days += (cnt / k) ;
                cnt = 0 ; 
            }       
        }
        days += (cnt / k) ;
        return days >= m ;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size() ;
        int s = *min_element(arr.begin() , arr.end()) ;
        int e = *max_element(arr.begin() , arr.end()) ;

        ll val =  m * 1LL * k * 1LL ;
        if(val > n)
            return -1 ;

        while(s <= e){
            int mid = ( s + e) / 2 ;
            if(poss(arr , m , k , mid))
                e = mid - 1 ;
            else
                s = mid + 1 ;    
        }    
        return s ;
    }
};
