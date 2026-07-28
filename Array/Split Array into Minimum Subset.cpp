class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        int n = arr.size() ; 
        sort(arr.begin() , arr.end()) ; 
        
        int prev = arr[0] ; 
        int cnt = 1 ; 
        for(int i =1 ; i< n ;i++ ){
            int num = arr[i] ; 
            if(prev + 1 != num)
                cnt++ ; 
            
            prev = num ;     
        }
        return cnt ;
    }
};
