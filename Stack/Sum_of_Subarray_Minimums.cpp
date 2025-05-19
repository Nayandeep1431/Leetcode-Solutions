class Solution {
    int mod = 1e9 + 7;

    vector<int> nse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> next = nse(arr);
        vector<int> prev = pse(arr);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long right = next[i] - i;
            long long left = i - prev[i];
            ans = (ans + (left * right % mod * arr[i]) % mod) % mod;
        }
        return ans;
    }
};
