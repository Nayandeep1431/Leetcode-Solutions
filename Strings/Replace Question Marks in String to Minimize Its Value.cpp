class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        vector<int> vis(26, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] != '?')
                vis[s[i] - 'a']++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < 26; i++) {
            pq.push({vis[i], i});
        }

        string t = "" ;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                auto [freq, ele] = pq.top();
                pq.pop();

                pq.push({freq + 1, ele});
                t.push_back(ele + 'a');
            }
        }
        sort(t.begin() , t.end()) ;
        int j = 0 ;
        for(int i =0 ; i< n ; i++){
            if(s[i] == '?'){
                s[i] = t[j] ;
                j++ ;
            }
        }

        return s;
    }
};
