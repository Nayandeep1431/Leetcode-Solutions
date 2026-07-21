class Solution {
  public:

    int maxIndexDifference(string &s) {
        // code here
       int first = -1 ; 
       int n = s.length() ; 
       vector<int> ind(26 , -1) ;
       int maxi = 0 ; 
       for(int i =0 ; i< n ; i++){
           int ch = s[i] - 'a' ; 
           if(ch == 0){
            if(first == -1)
             first = i ;
            
            ind[0] = first ;  
           }
           else{
               if(ind[ch - 1] != -1){
                ind[ch] = i ;
                maxi = max(maxi , i - first) ; 
               }    
           }
       }
       if(first == -1)
        return -1 ; 
        return maxi ; 
    }
};
