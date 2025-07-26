class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& v, int k) {
        int n = v.size();
        sort(v.rbegin(), v.rend()); 
        long long ans = 0;
        map<int, int> m;
        for(int i = 0; i < k; i++){
            ans += v[i][0];
            m[v[i][1]]++;
        }
        long long sz = m.size();
        ans += (sz * sz);
        long long res = ans;
        int j = k - 1;
        for(int i = k; i < n; i++){
            if(m.count(v[i][1]) == 0){ 
                while(j >= 0 && m[v[j][1]] < 2) j--; 
                if(j < 0) break; 
                m[v[j][1]]--;
                m[v[i][1]]++; 
                res -= v[j][0];
                res += v[i][0];
                res -= sz*sz;
                sz++;
                res += sz*sz;
                j--;
                ans = max(ans, res); 
            }
        }
        return max(ans, res);
    }
};
