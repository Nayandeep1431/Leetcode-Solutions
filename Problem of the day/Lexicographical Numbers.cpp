class Solution {
    void solve(int num , int &n , vector<int> &ans ){
        if(num > n)
            return ;

        for(int i = 0 ; i<= 9 ; i++){
            int val = num * 10 + i ;
            if(val <= n){
                ans.push_back(val) ;
                solve(val , n  , ans) ;
            }
        }    
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i<= min(n ,9) ; i++){
            int num = i ;
            ans.push_back(num) ; 
            solve(num , n , ans) ;
        }
        return ans ;
    }
};
