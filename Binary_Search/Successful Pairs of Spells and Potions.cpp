class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size() ;
        int m = potions.size() ;
        sort(potions.begin() , potions.end()) ;

        vector<int> ans;
        for(int i =0 ; i< n ; i++ ){
            int ele = spells[i] ;
            long long div = (ele + success - 1)/ele ;
            long ind = lower_bound(potions.begin() , potions.end() , div) - potions.begin() ;

            if(ind == m)
                ans.push_back(0) ;
            else
                ans.push_back(m - ind) ;    

        }
        return ans ;
    }
};
