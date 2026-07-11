class Solution {
public:
    typedef long long ll ; 
    ll power(int n){
        ll ans = 1 ; 
        for(int i = 1 ; i<= n ; i++)
            ans *= 10  ; 
        return ans ;    
    }
    vector<int> numsSameConsecDiff(int n, int k) {
       ll low = power(n-1) , high = power(n) - 1 ; 
       queue<ll> q ; 
       for(int i =1 ; i<= 9 ; i++)
        q.push(i) ; 
        vector<int> ans ;
       while(!q.empty()){
            ll num = q.front() ; 
            q.pop() ;

            if(num > high)
                continue ; 

            if(num >= low)
                ans.push_back(num) ;

            int prev = num % 10 ; 
            for(int i = 0 ; i<= 9 ; i++){
                if(abs(prev - i) == k){
                    ll newNumber = num * 10 + i ;
                    q.push(newNumber) ; 
                }
            }    
       } 
       sort(ans.begin() , ans.end()) ; 
       return ans ;
    }
};
