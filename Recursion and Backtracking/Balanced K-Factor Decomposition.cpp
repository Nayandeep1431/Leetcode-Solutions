class Solution {
public:
    vector<int> best ;
    int maxDiff = INT_MAX ;

    void check(vector<int> &curr){
        int mini = *min_element(curr.begin() , curr.end()) ;
        int maxi =  *max_element(curr.begin() , curr.end()) ;
        if(maxi - mini < maxDiff){
            maxDiff = maxi - mini ;
            best = curr ;
        }
    }

    void dfs(int n , int k ,int s , vector<int> &curr){
        if(k == 1){
            if(n >= s){
                curr.push_back(n) ;
                check(curr) ;
                curr.pop_back() ;
            }
            return ;
        }
        for(int i = s ; i<= n ; i++){
            if(n % i == 0){
                curr.push_back(i) ;
                dfs(n / i , k-1 ,i , curr) ;
                curr.pop_back() ;
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        int start =  1;
        vector<int> curr ;
        dfs(n , k , start ,curr) ;
        return best ;
    }
};
