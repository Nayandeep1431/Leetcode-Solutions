class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1] ; 
        else
            return a[0] < b[0] ;     
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ; 
        sort(intervals.begin() , intervals.end() , cmp) ; 

        int cnt = 0 ;
        int first = -1 , last = -1 ; 
        for(auto it : intervals){
            int f = it[0]; 
            int l = it[1] ; 

            if(f > last){
                first = f ; 
                last = l ;
            }
            else if(f >= first && l <= last)
                cnt++ ; 
            else 
                last = l ;    
        }
        return n - cnt ;
    }
};
