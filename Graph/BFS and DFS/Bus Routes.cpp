class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBus;

        int n = routes.size();

        for(int i = 0; i < n; i++) {
            for(int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> visitedBus(n, false);
        unordered_set<int> visitedStop;

        for(int bus : stopToBus[source]) {
            q.push(bus);
            visitedBus[bus] = true;
        }

        visitedStop.insert(source);

        int buses = 1;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int bus = q.front();
                q.pop();

                for(int stop : routes[bus]) {

                    if(stop == target)
                        return buses;

                    if(visitedStop.count(stop))
                        continue;

                    visitedStop.insert(stop);

                    for(int nextBus : stopToBus[stop]) {

                        if(!visitedBus[nextBus]) {
                            visitedBus[nextBus] = true;
                            q.push(nextBus);
                        }
                    }
                }
            }

            buses++;
        }

        return -1;
    }
};
