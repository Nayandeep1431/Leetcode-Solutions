class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
         int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[hand[i]]++;
        }

        while (!mpp.empty()) {
            int start = mpp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if (mpp.find(curr) == mpp.end()) {
                    return false;
                }
                mpp[curr]--;
                if (mpp[curr] == 0) {
                    mpp.erase(curr);
                }
            }
        }
        return true;
    }
};
