class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size() ;
        int movea = 0 ,moveb = 0 ;
        int cnta = 0 , cntb = 0 ;
        for(int i =0 ; i< n ; i++){
            char ch = colors[i] ;
            if(ch == 'A'){
                moveb += (cntb > 2 ) ? cntb - 2 : 0 ;
                cntb = 0 ;
                cnta++ ;
            }
            else{
                movea += (cnta > 2) ? cnta - 2 : 0 ;
                cnta = 0 ;
                cntb++ ;
            }
        }
        movea += (cnta > 2) ? cnta - 2 : 0 ;
        moveb += (cntb > 2 ) ? cntb - 2 : 0 ;
        return movea > moveb ;
    }
};
