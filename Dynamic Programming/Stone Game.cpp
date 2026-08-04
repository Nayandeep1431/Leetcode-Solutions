class Solution {
public:
    int n ; 
// Appraoch 1     
    int solve(int i , int j , vector<int> &piles){
        if(i > j)
            return 0 ; 

        int take_i = piles[i] + min(solve(i+2 ,j , piles) , solve(i+1 , j-1 , piles)) ; 
        int take_j = piles[j] + min(solve(i , j-2 , piles) , solve(i+1 , j-1 , piles)) ;

        return max(take_i , take_j) ; 
    }

// Approach 2 
    int solve2(int i , int j , vector<int> &piles){
        if(i = j)
            return piles[i] ; 

        int take_i = piles[i] - solve(i+1 , j , piles) ; 
        int take_j = piles[j] - solve(i , j-1 , piles) ;

        return max(take_i , take_j) ; 
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size() ; 
        int total = accumulate(piles.begin() , piles.end() , 0) ; 
        int value = solve2(0 , n-1 , piles) ; 

        return (value) >= 0 ; 
    }
};

