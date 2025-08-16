class Solution {
public:
    void solve(int ind , string &curr , unordered_set<string> &st , vector<string> &res , string s){
        if(ind >= s.length()){
            res.push_back(curr) ;
            return  ;
        }

        for(int j = ind ; j< s.length() ; j++){
            string temp = s.substr(ind , j- ind+1) ;
            if(st.find(temp) != st.end()){
                string org = curr ;

                if(!curr.empty())
                    curr += " " ;

                curr += temp ;
                solve(j+1 , curr , st ,res ,s) ;
                curr = org ;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& w) {
        unordered_set<string> st(w.begin() , w.end()) ;
        string curr = "" ;
        vector<string> res ;
        solve(0 , curr , st , res , s) ;
        return res ;
    }
};
