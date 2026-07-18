class Solution {
public:
    int findGCD(vector<int>& arr) {
        int n = arr.size() , maxi = INT_MIN , mini = INT_MAX ; 
        for(int i =0 ; i< n; i++){
            maxi = max(maxi , arr[i]) ; 
            mini = min(mini , arr[i]) ; 
        }
        return gcd(maxi , mini) ; 
    }
};
