class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int currX = coordinates[k][0], currY = coordinates[k][1];
        sort(coordinates.begin(), coordinates.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> before, after;
        for (auto &c:coordinates) {
            if (c[0] < currX && c[1] < currY) {
                auto it = lower_bound(begin(before), end(before), c[1]);
                if (it == before.end()) {
                    before.push_back(c[1]);
                } else {
                    *it = c[1];
                }
            } else if (c[0] > currX && c[1] > currY) {
                auto it = lower_bound(begin(after), end(after), c[1]);
                if (it == after.end()) {
                    after.push_back(c[1]);
                } else {
                    *it = c[1];
                }
            }
        }

        return before.size() + 1 + after.size();
    }
};