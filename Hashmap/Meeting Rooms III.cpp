class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int m = meetings.size();
        vector<int> used(n, 0);
        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> avaiRooms;

        for (int i = 0; i < n; i++) {
            avaiRooms.push(i);
        }

        for (vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                avaiRooms.push(room);
            }

            if (!avaiRooms.empty()) {
                int room = avaiRooms.top(); avaiRooms.pop();
                usedRooms.push({end, room});
                used[room]++;
            } else {
                auto [endTime, room] = usedRooms.top(); usedRooms.pop();
                usedRooms.push({endTime + duration, room});
                used[room]++;
            }
        }

        int maxi = 0, ind = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] > maxi) {
                maxi = used[i];
                ind = i;
            }
        }
        return ind;
    }
};
