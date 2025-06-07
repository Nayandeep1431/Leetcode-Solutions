class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        
    int n = a1.size();
    int res = 0;
    
    unordered_map<int, int> diffMap;
    
    int sum1 = 0, sum2 = 0;
    
    for (int i = 0; i < n; i++) {
        sum1 += a1[i];
        sum2 += a2[i];
        
        int currentDiff = sum1 - sum2;
        
        if (currentDiff == 0) {
            res = max(res, i + 1);
        }

        else if (diffMap.find(currentDiff) != diffMap.end()) {
            res = max(res, i - diffMap[currentDiff]);
        } 
        else {

            diffMap[currentDiff] = i;
        }
    }
    
    return res;
    }
};
