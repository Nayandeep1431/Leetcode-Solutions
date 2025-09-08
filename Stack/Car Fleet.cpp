class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size() ;
        vector<pair<int , int>> arr ;
        for(int i =0 ; i< n ; i++){
            arr.push_back({position[i] , speed[i]}) ;
        }
        sort(arr.begin() , arr.end()) ;
        stack<float> st ;
        for(int i =0 ; i< n ; i++){
            float time = (float)(target - arr[i].first) / arr[i].second ;
            while(!st.empty() && time >= st.top())
                st.pop() ;
            st.push(time) ;    
        }
        return st.size() ;
    }
};
