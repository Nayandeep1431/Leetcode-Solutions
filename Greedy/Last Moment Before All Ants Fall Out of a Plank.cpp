class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = INT_MIN ;
        for(int i =0 ; i< left.size() ; i++){
            int pos = left[i] ;
            maxi = max(maxi , pos - 0) ;
        }
        for(int i =0 ; i< right.size() ; i++){
            int pos = right[i] ;
            maxi = max(maxi , n - pos) ;
        }
        return maxi ;
    }
};
