class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n ==0)
            return 0 ;

        int maxi = INT_MIN ;
        int maxCnt = 0;
        int len = 1;
        for(int i =0 ; i< n ; i++){
            maxi = max(maxi , arr[i]);
        }
        for(int i =0 ; i< n ; i++){
            if(arr[i] == maxi){
                maxCnt++;
            }
            else{
                len = max(len , maxCnt);
                maxCnt =0 ;
            }
        }
        len = max(len , maxCnt);
        return len ;
    }
};
