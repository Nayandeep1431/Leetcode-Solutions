// Recursion
class Solution {
public:
    int findTheWinner(int n, int k) { 
        return winnerHelper(n, k) + 1; 
    }

private:
    int winnerHelper(int n, int k) {
        if (n == 1) return 0;
        return (winnerHelper(n - 1, k) + k) % n;
    }
};

// Using Queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q ;
        for(int i = 1; i<= n ; i++){
            q.push(i) ;
        }

        while(!q.empty()){
            if(q.size() == 1)
                return q.front() ;

            for(int i = 0 ; i< k-1 ; i++){
                q.push(q.front()) ;
                q.pop() ;
            }    
            q.pop() ;
        }
        return -1 ;
    }
};
