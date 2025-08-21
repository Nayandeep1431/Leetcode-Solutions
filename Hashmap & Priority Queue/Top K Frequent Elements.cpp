class Solution {
public:
    typedef pair<int , int> p ;
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size() ;
        priority_queue<p , vector<p> , greater<p>> pq ;
        int cnt = 1 ;
        sort(arr.begin() , arr.end()) ;
        int prev = arr[0] ;
        for(int i = 1 ; i< n ; i++ ){
            int ele = arr[i] ;
            if(ele == prev)
                cnt++ ;
            else{
                if(pq.size() >= k){
                    if(cnt > pq.top().first){
                        pq.pop() ;
                        pq.push({cnt , prev}) ;
                    }
                }
                else{
                    pq.push({cnt , prev}) ;
                }
                cnt = 1 ;
                prev = ele ;
            }    
        }
        if(pq.size() >= k){
            if(cnt > pq.top().first){
                pq.pop() ;
                pq.push({cnt , prev}) ;
            }
        }
        else{
            pq.push({cnt , prev}) ;
        }
        
        vector<int> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top().second) ;
            pq.pop() ;
        }
        return ans ;
    }
};
