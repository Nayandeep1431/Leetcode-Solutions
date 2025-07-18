class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size() ;

        vector<pair<double , int>> arr ;
        for(int i =0 ; i< n ; i++){
            double ratio = (double)wage[i] /quality[i] ;
            arr.push_back({ratio , quality[i]}) ;
        } 
        sort(arr.begin() , arr.end()) ;
        priority_queue<int> pq ;
        double sum = 0 ;
        for(int i = 0 ; i< k ; i++){
            pq.push(arr[i].second) ;
            sum += arr[i].second ;
        }
        double managerRatio = arr[k-1].first ;
        double res = managerRatio * sum ;

        for(int i = k ; i< n ; i++){
            managerRatio = arr[i].first ;
            pq.push(arr[i].second) ;
            sum += arr[i].second ;

            if(pq.size() > k){
                sum -= pq.top() ;
                pq.pop() ;
            }
            res = min(res , managerRatio * sum ) ;
        }
        return res ;
    }
};
