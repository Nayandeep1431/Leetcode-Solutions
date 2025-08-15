class Solution {
  public:
   static bool compare(const string &a , const string &b){
        return (a + b) > (b + a) ;
    }
    
    string rem(string s)
    {
        int n = s.length() ;
        for(int i =0 ; i< n ; i++){
            if(s[i] != '0')
                return s.substr(i) ;
        }
        return "" ;        
    }
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size() ;
        vector<string> nums ;
        for(int i =0 ; i< n ; i++){
            string s = to_string(arr[i]) ;
            nums.push_back(s) ;
        }
        sort(nums.begin(), nums.end() , compare) ;
        
        string ans = "" ;
        for(int i =0 ; i< n ; i++)
            ans += nums[i] ;
        
        ans = rem(ans) ;
        if(ans.size() > 0)
            return ans ;
        return "0" ;    
    }
};
