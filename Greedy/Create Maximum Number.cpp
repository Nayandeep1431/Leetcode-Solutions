class Solution {
public:
string solve(vector<int> &nums, int k) {
    int n = nums.size();
    string s = "";
    for (int i = 0; i < n; i++) {
        while (!s.empty() && (nums[i] + '0' > s.back()) && (s.size() - 1 + n - i >= k)) {
            s.pop_back();
        }
        if (s.size() < k)
            s.push_back(nums[i] + '0');
    }
    return s;
}

vector<int> merge(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (s1.substr(i) > s2.substr(j)) {
            ans.push_back(s1[i++] - '0');
        } else {
            ans.push_back(s2[j++] - '0');
        }
    }

    while (i < n) ans.push_back(s1[i++] - '0');
    while (j < m) ans.push_back(s2[j++] - '0');

    return ans;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    vector<int> ans;

    for (int i = 0; i <= k; i++) {
        if (i > n || (k - i) > m) continue;

        string s1 = solve(nums1, i);
        string s2 = solve(nums2, k - i);
        vector<int> temp = merge(s1, s2);

        if (temp.size() == k)
            ans = max(ans, temp);
    }
    return ans;
}

};
