class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size() ; 
        vector<int> mpp(26 , 0) ; 
        for(char &ch : tasks)
            mpp[ch - 'A']++ ;

        sort(mpp.begin() , mpp.end()) ; 
        int maxi = mpp[25] ; 
        int g = maxi - 1 ; 
        int slots = g * p ; 
        for(int i = 24 ; i>= 0 ; i--){
            slots -= min(mpp[i] , g) ;
        } 
        if(slots > 0)
            return n + slots ;
        else
            return n ;       
    }
};
