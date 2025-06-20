class Solution {
public:
    int solve(int n , int k){
        if(n == 1)
            return 0 ;

   
        int val = solve(n -1, ceil((double)(k) / (double)(2.0)) ) ;
        if(val == 0){
           val = (k % 2 == 0) ? 1 : 0 ;
        }    
        else {
            val = (k % 2 == 0) ? 0 : 1 ;
        }
        return val ;
    }
    int kthGrammar(int n, int k) {
        return solve(n , k) ;
    }
};
