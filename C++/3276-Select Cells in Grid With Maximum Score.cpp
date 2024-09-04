// DP1
class Solution {
public:
    int row, col;
    int dfs(int ind, int bitmask, map<int, unordered_set<int>, greater<int>>& hmap, vector<vector<int>>& memo) {
        if (ind == hmap.size()) return 0;
        if (memo[ind][bitmask] != -1) return memo[ind][bitmask];

        auto it = hmap.begin();
        advance(it, ind);
        auto key = it->first;

        int res = dfs(ind+1, bitmask, hmap, memo);
        for (int idx:hmap[key]) {
            if ( (bitmask&(1<<idx)) == 0 ) {
                res = max(res, key + dfs(ind+1, bitmask^(1<<idx), hmap, memo));
            }
        }
        return memo[ind][bitmask] = res;
    }
    int maxScore(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        map<int, unordered_set<int>, greater<int>> hmap; // value: (set of row indices)

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                hmap[grid[r][c]].insert(r);
            }
        }
        int N = hmap.size();
        vector<vector<int>> memo(N, vector<int>((1<<row), -1));
        int res = dfs(0, 0, hmap, memo);

        return res;
    }
};

// DP2, different data structure, faster
class Solution {
public:
    int row, col;
    int dfs(int ind, int bitmask, vector<pair<int, vector<int>>>& val2row, vector<vector<int>>& memo) {
        if (ind == val2row.size()) return 0;
        if (memo[ind][bitmask] != -1) return memo[ind][bitmask];

        int keyVal = val2row[ind].first;
        int res = dfs(ind+1, bitmask, val2row, memo);
        for (int rowIdx:val2row[ind].second) {
            if ( (bitmask&(1<<rowIdx)) == 0 ) {
                res = max(res, keyVal + dfs(ind+1, bitmask^(1<<rowIdx), val2row, memo));
            }
        }
        return memo[ind][bitmask] = res;
    }
    int maxScore(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        unordered_map<int, vector<int>> hmap; // value: (set of row indices)

        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                hmap[grid[r][c]].push_back(r);
            }
        }
        
        int N = hmap.size();
        vector<pair<int, vector<int>>> val2row(hmap.begin(), hmap.end());
        vector<vector<int>> memo(N, vector<int>((1<<row), -1));
        int res = dfs(0, 0, val2row, memo);

        return res;
    }
};