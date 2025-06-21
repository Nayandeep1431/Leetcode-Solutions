class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size() ;
        vector<int> freq(26 ,0) ;
        for(int i =0 ; i< n ; i++){
            int ch = word[i] - 'a' ;
            freq[ch]++ ;
        }
        int mini = INT_MAX ;
        for(int i =0 ; i < 26 ; i++){
            if(freq[i] == 0)
                continue ;

            int val = freq[i] ;   
            int cnt = 0 ; 
            for(int j =0 ; j < 26 ; j++){
                if(i == j)
                    continue ;

                if(freq[j] < val)
                    cnt += freq[j] ; 
                else if(freq[j] > val + k)
                    cnt += freq[j] - val - k ;    
            }
            mini = min(mini , cnt) ; 
        }
        return mini ;
    }
};
