class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int currx = points[i][0];
            int curry = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int nextx = points[j][0];
                int nexty = points[j][1];

                if ((currx <= nextx && curry >= nexty) || (currx >= nextx && curry <= nexty)) {
                    bool isValid = true;
                    pair<int, int> xrange = {min(currx, nextx), max(currx, nextx)};
                    pair<int, int> yrange = {min(curry, nexty), max(curry, nexty)};

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j)
                            continue;

                        int x = points[k][0];
                        int y = points[k][1];
                        if (x >= xrange.first && x <= xrange.second && y >= yrange.first && y <= yrange.second) {
                            isValid = false;
                            break;
                        }
                    }
                    if (isValid)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
