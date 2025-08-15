class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, list<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }
        int ans = 0;
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        while (!q.empty()) {
            int len = q.size();
            for (int j = 0; j < len; j++) {
                int ind = q.front();
                q.pop();
                if (ind == n - 1)
                    return ans;
             
                if (ind + 1 < n && !vis[ind + 1]) {
                    q.push(ind + 1);
                    vis[ind + 1] = true;
                }
                if (ind - 1 >= 0 && !vis[ind - 1]) {
                    q.push(ind - 1);
                    vis[ind - 1] = true;
                }
        
                for (auto it : mpp[arr[ind]]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
                mpp.erase(arr[ind]);
            }
            ans++;
        }
        return -1;
    }
};
