class Solution {
public:
    typedef long long ll;
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> leftHalf;
        priority_queue<int, vector<int>, greater<int>> rightHalf;
        ll n = nums.size() / 3;
        ll l = 0, r = 0;
        ll ans = LLONG_MAX;
        vector<ll> temp(nums.size(), 0);

        for (int i = nums.size() - 1; i >= n; i--) {
            rightHalf.push(nums[i]);
            r += nums[i];
            if (rightHalf.size() > n) {
                r -= rightHalf.top();
                rightHalf.pop();
            }
            if (rightHalf.size() == n)
                temp[i] = r;
        }

        l = 0;
        while (!leftHalf.empty()) leftHalf.pop();

        for (int i = 0; i < nums.size()-n; i++) {
            leftHalf.push(nums[i]);
            l += nums[i];
            if (leftHalf.size() > n) {
                l -= leftHalf.top();
                leftHalf.pop();
            }
            if (leftHalf.size() == n && i + 1 < nums.size())
                ans = min(ans, l - temp[i + 1]);
        }

        return ans;
    }
};
