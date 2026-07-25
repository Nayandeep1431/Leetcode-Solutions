class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size() ; 
        vector<vector<int>> ans ; 
        int i = 0 ; 
        int level = 0 ; 
        
        while(i < n){
            int size = pow(2 , level) ; 
            vector<int> temp ; 
            for(int j = i ; j< min(i + size , n) ; j++){
                temp.push_back(arr[j]) ; 
            }
            i += size ; 
            level++ ;
            sort(temp.begin() , temp.end()) ;
            ans.push_back(temp) ; 
        }
        return ans ; 
    }
};
