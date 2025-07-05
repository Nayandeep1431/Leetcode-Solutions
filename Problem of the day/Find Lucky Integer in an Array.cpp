class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size() ;
        map<int, int> mpp ;
        for(int i =0 ; i< n ; i++){
            mpp[arr[i]]++ ;
        }
        int maxi = -1 ;
        for(auto it : mpp){
            if(it.first == it.second)
                maxi = it.first ;
        }
        return maxi ;
    }
};
