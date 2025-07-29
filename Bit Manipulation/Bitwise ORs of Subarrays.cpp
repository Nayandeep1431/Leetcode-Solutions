class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev , unique ;
        int n = arr.size() ;
        for(int i = 0 ; i< n ; i++){
            unordered_set<int> curr ;
            curr.insert(arr[i]) ;
            unique.insert(arr[i]) ;
            for(auto it : prev){
                curr.insert(it | arr[i]) ;
                unique.insert(it | arr[i]) ;
            }
            prev = curr ;
        }
        return unique.size() ;
    }
};
