class Solution {
  public:
    pair<int , int> solve(int n){
        int one = 0 , two = 0 ; 
        while(n > 0){
            if(n & 1){
                one++ ; 
                n -= 1 ; 
            }
            else{
                two ++ ; 
                n/=2 ; 
            }
        }
        return {one ,two} ; 
    }
    int countMinOperations(vector<int>& arr) {
        // code here
        int n = arr.size() ; 
        int cnt = 0  ;
        int maxi = 0 ; 
        for(int i =0 ; i< n ; i++){
            auto [o ,t] = solve(arr[i]) ; 
            cnt += o ; 
            maxi = max(maxi , t) ;
        }
        cnt += maxi ; 
        return cnt ; 
    }
};
