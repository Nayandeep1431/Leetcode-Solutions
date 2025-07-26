class Solution {
public:
    typedef long long ll ;
    static bool cmp(const pair<int ,int> &a , const pair<int ,int> &b){
        return a.second > b.second ;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() ;
        vector<pair<int , int>> arr;
        for(int i =0 ; i< n ;i++){
            arr.push_back({nums1[i] , nums2[i]}) ;
        }

        sort(arr.begin() , arr.end() , cmp) ;
        priority_queue<int ,vector<int> , greater<int> > pq ;

        ll sum = 0 ;
        for(int i =0 ; i< k ;i++){
            sum += arr[i].first ;
            pq.push(arr[i].first) ;
        }

        ll res = sum * arr[k-1].second ;
        for(int i = k ; i < n ; i++){
            sum += arr[i].first - pq.top() ;
            pq.pop() ;
            pq.push(arr[i].first) ;

            res = max(res , sum * arr[i].second) ;
        }
        return res ;
    }
};
