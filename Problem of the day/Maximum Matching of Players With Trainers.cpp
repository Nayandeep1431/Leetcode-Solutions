class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size() ;
        int m = trainers.size() ;

        sort(players.begin() ,players.end()) ;
        sort(trainers.begin() , trainers.end()) ;

        int i =0 , j =0 ;
        int cnt = 0 ;
        while(i < n && j < m){
            if(players[i] <= trainers[j]){
                i++ ;
                j++; 
                cnt++ ;
            }
            else if(trainers[j] < players[i])
                j++ ;
        }
        return cnt ;
    }
};
