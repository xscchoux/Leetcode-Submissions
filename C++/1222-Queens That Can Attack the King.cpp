class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int N = 8;
        unordered_set<int> s;
        for (auto q:queens) {
            int u = q[0], v = q[1];
            s.insert(u*8+v);
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<int>> res;
        for (auto &[dx, dy]:directions) {
            int sx = king[0], sy = king[1];
            sx += dx;
            sy += dy;
            while (0<=sx && sx < N && 0<=sy && sy <N) {
                if (s.contains(sx*N+sy)) {
                    res.push_back({sx, sy});
                    break;
                }
                sx += dx;
                sy += dy;
            }
        }

        return res;
    }
};