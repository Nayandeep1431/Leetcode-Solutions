class Solution {
  public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o')
            return true ;
        
        return false ;    
    }

    int countBalanced(vector<string>& arr) {
        // code here
        int n = arr.size() ;
        unordered_map<int , int> mpp ;
        int cnt = 0 ;
        int sum = 0 ;
        mpp[0] = 1 ;
        for(int i =0 ; i< n ; i++){
            string s = arr[i] ;
            int size = s.length() ;
            for(int j =0 ; j< size ; j++){
                if(isVowel(s[j]))
                    sum++ ;
                else
                    sum-- ;
                
                if(j == size -1){
                    cnt += mpp[sum] ;
                    mpp[sum]++ ;
                }    
            }
            
        }
        return cnt ;
    }
};
