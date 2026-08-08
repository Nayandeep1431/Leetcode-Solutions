class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length() ; 
        int m = word2.length() ; 

        vector<int> rightMatched(n , 0) ; 
        int i = n-1 , j = m-1 ; 
        int val = 0; 
        while(i >=0 ){
            if(j >= 0 && word1[i] == word2[j]){
                val ++ ; 
                j-- ; 
            }
            rightMatched[i] = val ;
            i-- ;  
        }
        vector<int> seq ; 
        bool changePower = true ;

        i = 0 , j = 0 ; 
        while(i < n && j < m ){
            if(word1[i] == word2[j]){
                seq.push_back(i) ; 
                j++ ; 
            }
            else if(changePower && i+1 < n && rightMatched[i+1] >= m-j-1){
                seq.push_back(i) ; 
                j++ ; 
                changePower = false ; 
            }
            i++ ; 
        }
        return (j == m) ? seq : vector<int>()  ;
    }
};
