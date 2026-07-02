class Solution {
public:
    typedef pair<int, pair<int,int>> P;

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!pq.empty()){

            auto [cost, cell] = pq.top();
            pq.pop();

            int x = cell.first;
            int y = cell.second;

            if(cost > dist[x][y])
                continue;

            for(int k=0;k<4;k++){

                int nx = x + dr[k];
                int ny = y + dc[k];

                if(nx<0 || ny<0 || nx>=n || ny>=m)
                    continue;

                int newCost = cost + grid[nx][ny];

                if(newCost < dist[nx][ny]){
                    dist[nx][ny] = newCost;
                    pq.push({newCost,{nx,ny}});
                }
            }
        }

        return dist[n-1][m-1] < health;
    }
};
