class Solution {
public:
    bool solve(int num , int t){
        int pro = 1 ; 
        while(num > 0){
            int dig = num % 10 ;
            pro *= dig ; 
            num /= 10 ; 
        }
        return (pro % t == 0) ; 
    }
    int smallestNumber(int n, int t) {
        bool flag = true ; 
        while(flag){
            if(solve(n , t))
                return n ; 
            n++ ;     
        }
        return false ; 
    }
};
