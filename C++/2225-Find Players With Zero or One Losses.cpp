class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2, vector<int>());
        unordered_map<int, int> hmap;
        for (vector<int>& match:matches) {
            int win = match[0], lose = match[1];
            if (hmap.find(win) == hmap.end()) {
                hmap[win] = 0;
            }
            hmap[lose]++;
        }
        
        for (auto &[k, v]:hmap) {
            if (v==0){
                res[0].push_back(k);
            } else if (v == 1) {
                res[1].push_back(k);
            }
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};