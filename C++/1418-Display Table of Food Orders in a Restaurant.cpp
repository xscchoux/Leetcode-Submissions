class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> cuisines;
        map<int, map<string, int>> hmap;
        for (auto &order:orders) {
            hmap[stoi(order[1])][order[2]]++;
            cuisines.insert(order[2]);
        }

        int row = hmap.size() + 1, col = cuisines.size() + 1;
        vector<vector<string>> res(row, vector<string>(col, "0"));

        res[0][0] = "Table";
        auto it = cuisines.begin();
        for (int r=0, c=1; it!=cuisines.end(); c++, it++) {
            res[r][c] = *it;
        }

        auto it2 = hmap.begin();
        for (auto r = 1 ; it2 != hmap.end(); it2++, r++) {
            res[r][0] = to_string(it2->first);
        }

        int rowIdx = 1;
        for (auto it = hmap.begin(); it != hmap.end(); it++) {
            if (res[rowIdx][0] != to_string(it->first)) {
                rowIdx++;
            }
            int rowNum = stoi(res[rowIdx][0]);
            auto it2 = hmap[rowNum].begin();
            int colIdx = 1;
            while (it2 != hmap[rowNum].end()) {
                auto &[cuisine, cnt] = *it2;
                while (res[0][colIdx] != cuisine) {
                    colIdx++;
                }
                string colName = res[0][colIdx];
                res[rowIdx][colIdx] = to_string(hmap[rowNum][colName]);
                it2++;
            }
        }
        return res;
    }
};