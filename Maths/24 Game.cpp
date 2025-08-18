class Solution {
public:
    double eps = 0.1 ;
    bool solve(vector<double> &nums){
        if(nums.size() == 1)
            return abs(24 - nums[0]) <= eps ;

        for(int i =0 ; i< nums.size() ; i++){
            for(int j =0 ; j< nums.size() ; j++){
                if( i == j )
                    continue ;

                vector<double> temp ;
                for(int k =0 ; k < nums.size() ; k++){
                    if(k != i && k != j)
                        temp.push_back(nums[k]) ;
                }    
                double a = nums[i] ;
                double b = nums[j] ;

                vector<double> poss = {a+b , a-b , b-a , a*b};
                if(abs(b) > 0.0)
                    poss.push_back(a / b) ;
                if(abs(a) > 0.0)
                    poss.push_back(b / a) ;

                for(auto it : poss){
                    temp.push_back(it) ;
                    if(solve(temp))
                        return true ;

                    temp.pop_back() ;    
                }        

            }
        }    
        return false ;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums ;
        for(int i =0 ; i< cards.size() ; i++){
            nums.push_back(1.0* cards[i]) ;
        }
        return solve(nums) ;
    }
};
