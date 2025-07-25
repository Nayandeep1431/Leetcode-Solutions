class Solution {
public:
    static bool cmp(vector<int> &a  , vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0] ;

        return a[1] < b[1] ;    
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size() ;
        sort(tasks.begin() ,tasks.end() , cmp) ;
        vector<int> vis(2001 , 0) ;

        for(int i =0 ; i< n ; i++){
            int start = tasks[i][0] ;
            int end = tasks[i][1] ;
            int duration = tasks[i][2] ;

            for(int j = start ; j <= end ; j++){
                if(vis[j])
                    duration-- ;
            }
            int j = end ;
            while(duration > 0 && j >= start){
                if(!vis[j]){
                    vis[j] = 1 ;
                    duration-- ;
                }
                j-- ;
            }
        }
        int time = 0 ;
        for(int i =0 ; i< 2001 ; i++){
            if(vis[i] == 1)
                time++ ;
        }
        return time ;
    }
};
