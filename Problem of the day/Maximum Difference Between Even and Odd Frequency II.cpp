class Solution {
public:
    int getState(int a , int b){
        int para = a % 2 ;
        int parb = b % 2 ;

        if(para == 0 && parb == 0) return 0 ;
        if(para == 0 && parb == 1) return 1 ;
        if(para == 1 && parb == 0) return 2 ;
        if(para == 1 && parb == 1) return 3 ;
        return -1;
    }

    int maxDifference(string s, int k) {
        int n = s.length() ;
        int res = INT_MIN ;

        // step 1 : try all possible pairs a and b from ('0' to '4') where a != b
        for(char a = '0' ; a <= '4' ; a++){
            for(char b = '0' ; b<= '4' ; b++){
                if(a == b)
                    continue ;

                // stateMinPrev_a_b[state] = stores the smallest value of count of a - count of b
                vector<int> stateMinPrev(4 , INT_MAX ) ;
                int cnta = 0 ;
                int cntb = 0 ;

                // count of a and cnt of b till prev index
                int prev_a = 0 ;
                int prev_b = 0 ;

                // lets start sliding window
                int l = -1 ;
                int r = 0 ;

                while(r < n){
                    cnta += (s[r] == a) ? 1 : 0 ;
                    cntb += (s[r] == b) ? 1 : 0 ;

                    // Now try to shrink to l 
                    while(r - l >= k && cntb - prev_b >= 2 && cnta - prev_a >= 1){
                        int leftState = getState(prev_a , prev_b) ;
                        stateMinPrev[leftState] = min(stateMinPrev[leftState] , prev_a - prev_b) ;
                        l++ ;
                        prev_a += (s[l] == a) ? 1 : 0 ;
                        prev_b += (s[l] == b) ? 1 : 0 ;
                    }

                    int rightState = getState(cnta , cntb) ;
                    int best = rightState ^ 2 ;
                    int bestMin = stateMinPrev[best] ;

                    if(bestMin != INT_MAX)
                        res = max(res , (cnta - cntb) - bestMin) ;

                    r++ ;    
                }    
            }
        }
        return res ;
    }
};
