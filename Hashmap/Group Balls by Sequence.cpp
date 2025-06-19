class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % k != 0)
            return false;
        
        map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }

        while (!mpp.empty()) {
            int ele = mpp.begin()->first; 

            for (int i = 0; i < k; i++) {
                if (mpp.find(ele + i) == mpp.end())
                    return false;
                mpp[ele + i]--;
                if (mpp[ele + i] == 0)
                    mpp.erase(ele + i);
            }
        }
        return true;
    }
};
