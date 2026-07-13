class Solution {
public:
    typedef long long ll ; 
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans ; 
        queue<ll> q ;
        for(int i =1 ; i<= 9; i++ )
            q.push(i) ; 

        while(!q.empty()){
            ll top = q.front() ;
            q.pop() ; 

            if(top > high)
                continue ;

            if(top >= low)
                ans.push_back(top) ; 

            int last = top % 10 ; 

            for(int i = 0 ; i<= 9 ;  i++){
                if(i - last == 1){
                    ll next = top * 10 + i ; 
                    if(next <= high)
                        q.push(next) ;
                }
            }        
        }    
        sort(ans.begin() , ans.end()) ; 
        return ans ;
    }
};
