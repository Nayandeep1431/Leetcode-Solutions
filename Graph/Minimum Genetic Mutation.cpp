class Solution {
public:
    bool match(string s , string t){
        int cnt = 0 ;
        for(int i =0 ; i<s.length() ; i++){
            if(s[i] != t[i])
                cnt++ ;
        }
        return cnt == 1 ;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q ;
        int size = bank.size() ;
        q.push(startGene) ;
        vector<bool> vis(size , false) ;
        int cnt = 0 ;
        while(!q.empty()){
            int s = q.size() ;
            while(s--){
            string top = q.front() ;
            q.pop() ;
            
            if(top == endGene)
                return cnt ;


            for(int i =0 ; i< size ; i++){
                string t = bank[i] ;
                if(!vis[i] && match(top , t)){
                    q.push(t) ;
                    vis[i] = true ;
                }
            }
            }
            cnt++ ;
        }
        return -1 ;
    }
};
