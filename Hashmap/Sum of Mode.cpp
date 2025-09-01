class Solution {
  public:
    static bool comp(const pair<int , int> &a , const pair<int , int> &b){
        if(a.second == b.second)
            return a.first < b.first ;
        return a.second > b.second ;    
    }
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        multiset<pair<int, int>, decltype(&comp)> st(comp);
        vector<int> cnt(1e5+1 , 0);
        
        for(int i =0 ; i< k ; i++){
            int ele = arr[i];
            if(st.find({ele , cnt[ele]}) != st.end()){
                st.erase(st.find({ele , cnt[ele]}));
            }
            cnt[ele]++;
            st.insert({ele , cnt[ele]});
        }
        
        int sum =0;
        // cout<<st.begin() -> first<<endl  ;
        sum += st.begin()->first;
        
        for(int i = k ; i < n ; i++){
            int prev = arr[i-k];
            if(st.find({prev , cnt[prev]}) != st.end()){
                st.erase(st.find({prev , cnt[prev]}));
            }
            cnt[prev]--;
            if(cnt[prev] > 0)
                st.insert({prev, cnt[prev]});
            
            int ele = arr[i];
            if(st.find({ele , cnt[ele]}) != st.end()){
                st.erase(st.find({ele , cnt[ele]}));
            }
            cnt[ele]++;
            st.insert({ele , cnt[ele]});
            
            // cout<<st.begin() -> first<<endl  ;
            sum += st.begin()->first;
        }
        return sum;
    }
};
