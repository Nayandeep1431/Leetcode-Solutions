class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size() ;
        set<pair<int , int>> vis ;
        sort(a.rbegin() , a.rend()) ;
        sort(b.rbegin() , b.rend()) ;
        priority_queue<pair<int ,pair<int , int>>> pq ;
        
        vector<int> ans ;
        vis.insert({0 , 0}) ;
        pq.push({a[0] + b[0] ,{0 , 0}}) ;
        
        while(k-- && !pq.empty()){
            auto it = pq.top() ;
            pq.pop() ;
            
            int i = it.second.first ;
            int j = it.second.second ;
            
            ans.push_back({a[i] + b[j]}) ;
            
            if(i + 1 < n && vis.find({i+1 , j }) == vis.end()){
                pq.push({a[i+1] + b[j] , {i+1 , j}}) ;
                vis.insert({i+1 , j}) ;
            }
            if(j + 1 < n && vis.find({i , j+1 }) == vis.end()){
                pq.push({a[i] + b[j+1] , {i , j+1}}) ;
                vis.insert({i , j+1}) ;
            }            
        }
        return ans ;
    }
};
