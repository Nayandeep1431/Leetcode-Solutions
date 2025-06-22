class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length() ;
        vector<string> ans ;
        for(int i =0 ; i< n; i+=k){
            int mini = min(n-i , k) ;
            string sub = s.substr(i , mini) ;
            ans.push_back(sub) ;
        }
        string last = ans.back() ;
        int size = last.size() ;
        if(size == k)
            return ans ;
        else{
            for(int i =size ; i < k ; i++){
                last += fill ;
            }
            ans[ans.size()-1] = last ;
        }    
        return ans ;
    }
};
