class Solution {
    int width ;
    int n ;

    // Recursion
    int solve(vector<vector<int>>& books , int rem , int maxi ,int ind){
        if(ind >= n)
            return maxi ;

        int h = books[ind][1] ;
        int w = books[ind][0] ;

        int keep = INT_MAX , skip = INT_MAX ;
        if(w <= rem){
            keep = solve(books , rem - w , max(maxi , h) , ind+1) ;
        } 
        skip = maxi + solve(books ,width - w , h , ind+1 ) ;
        return min(skip , keep) ;   
    }

    // Memoization
int solveTab(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int width = 0, height = 0;
        for (int j = i; j >= 1; --j) {
            width += books[j - 1][0];
            if (width > shelfWidth) break;
            height = max(height, books[j - 1][1]);
            dp[i] = min(dp[i], dp[j - 1] + height);
        }
    }

    return dp[n];
}

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size() ;
        width = shelfWidth ;
        int maxHeight = 0 ;
        // return solve(books , shelfWidth ,maxHeight , 0 ) ;

        vector<vector<int>> dp(n , vector<int>(shelfWidth+1 , -1)) ;
        // return solveMem(books , shelfWidth ,maxHeight , 0 , dp ) ;

        return solveTab(books  , shelfWidth) ;
    }
};
