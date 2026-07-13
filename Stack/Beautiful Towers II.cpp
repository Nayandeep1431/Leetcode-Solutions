class Solution {
public:
    typedef long long ll;

    vector<int> nse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<ll> calPre(vector<int> &arr, vector<int> &pse) {
        int n = arr.size();
        vector<ll> ans(n);

        for (int i = 0; i < n; i++) {

            if (pse[i] == -1) {
                ans[i] = 1LL * (i + 1) * arr[i];
            }
            else {
                ll len = i - pse[i];
                ans[i] = ans[pse[i]] + len * arr[i];
            }
        }

        return ans;
    }

    vector<ll> calSuff(vector<int> &arr, vector<int> &nse) {
        int n = arr.size();
        vector<ll> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            if (nse[i] == -1) {
                ans[i] = 1LL * (n - i) * arr[i];
            }
            else {
                ll len = nse[i] - i;
                ans[i] = ans[nse[i]] + len * arr[i];
            }
        }

        return ans;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {

        int n = maxHeights.size();

        vector<int> ps = pse(maxHeights);
        vector<ll> pre = calPre(maxHeights, ps);

        vector<int> ns = nse(maxHeights);
        vector<ll> suff = calSuff(maxHeights, ns);

        ll ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i] + suff[i] - maxHeights[i]);
        }

        return ans;
    }
};
