class Solution {
public:
    void insert(vector<int> &arr ,int times , int ele){
        for(int i =1 ; i<= times ; i++){
            arr.push_back(ele) ;
        }
    }
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size() ;
        unordered_map<int , int> mpp1 , mpp2 ;
        for(int i =0 ; i< n ; i++){
            mpp1[basket1[i]]++ ;
            mpp2[basket2[i]]++ ;
        }
        vector<int> ans ;
        int mini = INT_MAX ;
        for(auto it : mpp1){
            int ele = it.first ;
            mini = min(mini , ele) ;
            if(mpp2.find(ele) != mpp2.end()){
                if((mpp1[ele] + mpp2[ele]) % 2 == 1)
                    return -1 ;
                if(mpp1[ele] == mpp2[ele]){
                    mpp2.erase(ele) ;
                }
                else if(mpp1[ele] != mpp2[ele]){
                    int diff = abs(mpp1[ele] - mpp2[ele]) ;
                    insert(ans , diff / 2 , ele ) ;
                    mpp2.erase(ele) ;
                }
            }
            else{
                if(mpp1[ele] % 2 == 1)
                    return -1 ;
                else{
                    int diff = mpp1[ele] / 2 ;
                    insert(ans , diff ,ele) ;
                }    
            }
        }
        for(auto it : mpp2){
            int ele = it.first ;
            mini = min(mini , ele) ;
            if(mpp2[ele] % 2 == 1)
                return -1 ;

            int diff = mpp2[ele] ;
            insert(ans , diff / 2 ,ele) ;    
        }

        sort(ans.begin() , ans.end()) ;
        long long res = 0 ;
        int ind = ans.size() / 2 ;
        for(int i =0 ; i< ind ; i++ ){
            res += min((long long)ans[i] , (long long)mini * 2) ;
        }
        return res ;    
    }
};
