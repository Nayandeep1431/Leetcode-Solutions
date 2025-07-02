class Solution {
public:
    int mod = 1e9 + 7 ;

    // Recursion
    int solve(int ind , int cnt , vector<int> & freq , int k){
        if(ind >= freq.size()){
            if(cnt < k)
                return 1 ;
            else
                return 0 ;    
        }

        int res = 0 ;
        for(int i = 1 ; i <= freq[ind] ; i++){
            if(cnt + i < k){
                res = (res + solve(ind +1 , cnt + i , freq , k)) % mod ;
            }
            else
                break ;
        }
        return res ;
    }

    // Memoization
    int solveMem(int ind , int cnt , vector<int> & freq , int k , vector<vector<int>> &dp){
        if(ind >= freq.size()){
            if(cnt < k)
                return 1 ;
            else
                return 0 ;    
        }

        if(dp[ind][cnt] != -1)
            return dp[ind][cnt] ;

        int res = 0 ;
        for(int i = 1 ; i <= freq[ind] ; i++){
            if(cnt + i < k){
                res = (res + solveMem(ind +1 , cnt + i , freq , k ,dp)) % mod ;
            }
            else
                break ;
        }
        return res ;
    }
    
    // Tabulation
    int solveTab(vector<int> &freq , int k){
        int n = freq.size() ;
        vector<vector<int>> dp(n+1 , vector<int> (k+1 ,0)) ;
        for(int i = k-1 ; i>=0 ; i--){
            dp[n][i] = 1;
        }

        for(int i = n-1; i>=0 ; i-- ){
            for(int cnt = k-1 ; cnt >=0 ; cnt--){
                int res = 0 ;
                for(int take = 1 ; take <= freq[i] ; take++ ){
                    if(cnt + take < k)
                        res = (res + dp[i+1][cnt+take]) % mod;
                    else
                        break ;    
                }
                dp[i][cnt] = res ; 
            }
        }
        return dp[0][0] ;
    }

// Optimised Tabulation
    int solveTab2(vector<int> &freq , int k){
        int n = freq.size() ;
        vector<vector<int>> dp(n+1 , vector<int> (k+1 ,0)) ;
        for(int i = k-1 ; i>=0 ; i--){
            dp[n][i] = 1;
        }

        for(int i = n-1; i>=0 ; i-- ){
            vector<int>prefix(k+1 , 0) ;
            for(int h = 1; h<= k ; h++){
                prefix[h] = (prefix[h-1] + dp[i+1][h-1]) % mod ;
            }
            for(int cnt = k-1 ; cnt >=0 ; cnt--){
                int l = cnt + 1;
                int r = cnt + freq[i] ;
                
                if(r + 1 > k)
                    r = k- 1 ;

                if(l <= r)
                    dp[i][cnt] = (prefix[r+1] - prefix[l] + mod ) % mod ;
            }
        }
        return dp[0][0] ;
    }

    int possibleStringCount(string word, int k) {
        if( k > word.length())
            return 0 ;

        vector<int> freq ;
        int cnt = 1;
        for(int i =1 ; i< word.length() ; i++){
            if(word[i] == word[i-1])
                cnt++ ;
            else{
                freq.push_back(cnt) ;
                cnt = 1 ;
            }    
        }    
        freq.push_back(cnt) ;

        long long p = 1;
        for(int i =0 ; i< freq.size() ; i++){
            p = (p * freq[i]) % mod ;
        }
        if(freq.size() >= k)
            return p ;

        // int invalid = solve(0 , 0 , freq , k) ;

        //Memoization
        // vector<vector<int>> dp(freq.size() + 1 , vector<int> (k+1 , -1)) ;
        // int invalid = solveMem(0 ,0 , freq , k , dp) ;
        // return (p- invalid + mod) % mod ;    

        // Tabulation
        // int val = solveTab(freq , k) ;
        // return (p - val + mod) % mod ;

        int val2 = solveTab2(freq , k) ;
        return (p - val2 + mod ) % mod  ;
    }
};
