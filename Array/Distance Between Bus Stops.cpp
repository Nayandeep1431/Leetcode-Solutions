class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size() ; 
        int total = accumulate(distance.begin() , distance.end() , 0) ; 
        int sum = 0 ; 
        if(start > destination)
            swap(start , destination) ; 
            
        for(int i = start ; i< destination ; i++)
            sum += distance[i] ; 

        return min(sum , total - sum) ;     
    }
};
