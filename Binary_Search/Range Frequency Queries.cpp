class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {

        if (!mp.count(value))
            return 0;

        vector<int>& vec = mp[value];

        auto l = lower_bound(vec.begin(), vec.end(), left);
        auto r = upper_bound(vec.begin(), vec.end(), right);

        return r - l;
    }
};
