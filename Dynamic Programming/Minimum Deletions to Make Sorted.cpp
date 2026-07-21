class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        int n = arr.size() ; 
        vector<int> lis ; 
        lis.push_back(arr[0]) ;
        for(int i =1 ; i< n ; i++){
            int num = arr[i] ; 
            if(num > lis.back())
                lis.push_back(num) ; 
            else{
                int ind = lower_bound(lis.begin() , lis.end() , num) - lis.begin() ; 
                lis[ind] = num ; 
            }    
        }
        return n - lis.size() ; 
    }
};
