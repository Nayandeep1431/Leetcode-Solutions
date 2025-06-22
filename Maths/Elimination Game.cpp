class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1 ;
        bool left = true ;
        int rem = n ;
        while(rem > 1){
            if(left || rem & 1)
                head += step ;

            step *= 2 ;
            rem /= 2 ;
            left = !left ;    
        }
        return head ;
    }
};
