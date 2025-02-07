class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball2color, color2count;
        int numColor = 0;
        vector<int> res;

        for (auto &q:queries) {
            int u = q[0], v = q[1];
            if (ball2color.count(u)) {
                int prevColor = ball2color[u];
                if (--color2count[prevColor] == 0) numColor--;
            }
            ball2color[u] = v;
            if (++color2count[v] == 1) numColor++;
            res.push_back(numColor);
        }
        return res;
    }
};