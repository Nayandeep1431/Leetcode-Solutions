class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mpp[i - j].push_back(mat[i][j]);
            }
        }

        for (auto &it : mpp) {
            if(it.first >= 0)
                sort(it.second.begin(), it.second.end());
           else
                sort(it.second.rbegin(), it.second.rend()) ;
        }

        for (int i = 0 ; i< n ; i++) {
            for (int j = 0 ; j< m ; j++) {
                mat[i][j] = mpp[i - j].back();
                mpp[i - j].pop_back();
            }
        }
        return mat;
    }
};
