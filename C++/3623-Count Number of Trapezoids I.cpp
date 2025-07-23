class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> hmap;

        for (auto &p:points) {
            int y = p[1];
            hmap[y]++;
        }

        vector<long long> lineCnt;
        for (auto &[k, v]:hmap) {
            if (v > 1) {
                lineCnt.push_back((long long)v*(v-1)/2);
            }
        }

        int kMod = 1e9+7;
        long long res = 0;

        long long preSum = 0; // count previous lines
        for (int i=0; i<lineCnt.size(); i++) {
            if (i > 0) {
                res = (res + (lineCnt[i]*preSum)%kMod)%kMod;
            }
            preSum = (preSum + lineCnt[i])%kMod;
        }

        return res;
    }
};