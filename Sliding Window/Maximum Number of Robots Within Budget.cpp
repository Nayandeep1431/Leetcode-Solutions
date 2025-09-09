class Solution {
public:
    typedef long long ll;
    int maximumRobots(vector<int>& c, vector<int>& ri, long long budget) {
        int n = c.size();
        vector<ll> prefix(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == 0)
                prefix[i] = (ll)ri[i];
            else
                prefix[i] = prefix[i-1] + ri[i];
        }
        multiset<int> st;
        int maxi = 0;
        int l = 0, r = 0;
        while(r < n) {
            st.insert(c[r]);
            int k = (r - l + 1);
            ll sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l-1];
            ll total = *st.rbegin() + k * sum;
            while(l <= r && total > budget) {
                st.erase(st.find(c[l]));
                l++;
                k = (r - l + 1);
                sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l-1];
                total = (st.empty() ? 0 : *st.rbegin()) + k * sum;
            }
            maxi = max(maxi, k);
            r++;
        }
        return maxi;
    }
};
