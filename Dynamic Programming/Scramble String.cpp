class Solution {

    // Recursion
    bool solve(string s1 , string s2){
        if(s1 == s2)
            return true ;

        if(s1.length() != s2.length())
            return false ;

        int n = s1.length();
        for(int i = 1; i < n; i++){
            bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                           solve(s1.substr(i, n - i), s2.substr(0, n - i));

            if(swapped)
                return true;

            bool notSwapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                              solve(s1.substr(i, n - i), s2.substr(i, n - i));

            if(notSwapped)
                return true;
        }
        return false;
    }

//Memoization
unordered_map<string, bool> mpp;

bool solveMem(string s1, string s2) {
    if (s1 == s2)
        return true;

    if (s1.length() != s2.length())
        return false;

    string key = s1 + "_" + s2;
    if (mpp.find(key) != mpp.end())
        return mpp[key];

    int n = s1.length();
    bool res = false;
    for (int i = 1; i < n; i++) {
        bool swapped = solveMem(s1.substr(0, i), s2.substr(n - i, i)) &&
                       solveMem(s1.substr(i, n - i), s2.substr(0, n - i));

        if (swapped) {
            res = true;
            break;
        }

        bool notSwapped = solveMem(s1.substr(0, i), s2.substr(0, i)) &&
                          solveMem(s1.substr(i, n - i), s2.substr(i, n - i));

        if (notSwapped) {
            res = true;
            break;
        }
    }
    return mpp[key] = res;
}

public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;

        if(s1.length() != s2.length())
            return false;

        // return solve(s1, s2);     
        return solveMem(s1 , s2) ;   
    }
};
