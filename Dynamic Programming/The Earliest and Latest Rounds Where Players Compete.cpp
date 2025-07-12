class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);
        return solve(n, firstPlayer, secondPlayer);
    }

    vector<int> solve(int n, int left, int right) {
        if (left + right == n + 1) return {1, 1}; // base case: they meet this round

        if (left > n - right + 1) {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int next = (n + 1) / 2;
        int minRound = INT_MAX;
        int maxRound = INT_MIN;

        if (right <= next) { // both on the same side
            int cntLeft = left - 1;
            int cntMid = right - left - 1;

            for (int sl = 0; sl <= cntLeft; sl++) {
                for (int sm = 0; sm <= cntMid; sm++) {
                    int pos1 = sl + 1;
                    int pos2 = pos1 + sm + 1;
                    vector<int> res = solve(next, pos1, pos2);
                    minRound = min(minRound, res[0] + 1);
                    maxRound = max(maxRound, res[1] + 1);
                }
            }
        } else { // on opposite sides
            int fightsRight = n - right + 1;
            int cntLeft = left - 1;
            int cntMid = fightsRight - left - 1;
            int remMid = right - fightsRight - 1;

            for (int sl = 0; sl <= cntLeft; sl++) {
                for (int sm = 0; sm <= cntMid; sm++) {
                    int pos1 = sl + 1;
                    int pos2 = pos1 + sm + (remMid + 1) / 2 + 1;
                    vector<int> res = solve(next, pos1, pos2);
                    minRound = min(minRound, res[0] + 1);
                    maxRound = max(maxRound, res[1] + 1);
                }
            }
        }

        return {minRound, maxRound};
    }
};
