class Solution {
public:
    int res = 0;
    void dfs(unordered_map<char, int>& hmap) {
        for (auto &[k, v]:hmap) {
            if (v > 0) {
                hmap[k]--;
                res++;
                dfs(hmap);
                hmap[k]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> hmap;

        for (char c:tiles) {
            hmap[c]++;
        }

        dfs(hmap);

        return res;
    }
};