class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size() ;
        vector<int> vis(n , false) ;
        queue<int> q ;
        q.push(0) ;
        while(!q.empty()){
            int top = q.front() ;
            q.pop() ;

            vis[top] = true ;
            for(int i =0 ; i<rooms[top].size() ; i++){
                int node = rooms[top][i] ;
                if(!vis[node]){
                    q.push(node) ;
                    vis[node] = true ;
                }
            }
        }
        for(int i =0 ; i< n ; i++){
            if(vis[i] == 0)
                return false ;
        }
        return true ;
    }
};
