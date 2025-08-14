class Solution {
public:
    bool solve(vector<int>& arr, int ind, vector<bool>& visited) {
        if (ind < 0 || ind >= arr.size() || visited[ind])
             return false;
             
        if (arr[ind] == 0) 
            return true;
        
        visited[ind] = true;
        bool aage = solve(arr, ind + arr[ind], visited);
        bool piche = solve(arr, ind - arr[ind], visited);
        
        return aage || piche;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return solve(arr, start, visited);
    }
};
