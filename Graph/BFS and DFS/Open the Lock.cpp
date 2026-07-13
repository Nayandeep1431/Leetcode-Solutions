class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        set<string> st(deadends.begin(), deadends.end());

        if(st.count("0000"))
            return -1;

        queue<pair<string,int>> q;
        q.push({"0000", 0});

        st.insert("0000");      // mark visited

        while(!q.empty()) {

            auto cur = q.front();
            q.pop();

            string s = cur.first;
            int steps = cur.second;

            if(s == target)
                return steps;

            for(int i = 0; i < 4; i++) {

                // Rotate forward
                string up = s;
                up[i] = (up[i] == '9') ? '0' : up[i] + 1;

                if(!st.count(up)) {
                    st.insert(up);
                    q.push({up, steps + 1});
                }

                string down = s;
                down[i] = (down[i] == '0') ? '9' : down[i] - 1;

                if(!st.count(down)) {
                    st.insert(down);
                    q.push({down, steps + 1});
                }
            }
        }

        return -1;
    }
};
