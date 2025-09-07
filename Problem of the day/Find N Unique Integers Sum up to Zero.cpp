class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans ;
        if(n & 1){
            ans.push_back(0) ;
            n-=1 ;
        }
        int val = 1 ;
        while(ans.size() < n){
            ans.push_back(val) ;
            ans.push_back(-val) ;
            val++ ;
        }
        return ans ;
    }
};
