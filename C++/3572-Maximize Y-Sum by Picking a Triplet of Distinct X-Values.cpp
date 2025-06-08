class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> hmap1;

        for (int i=0; i<x.size(); i++) {
            hmap1[x[i]] = max(hmap1[x[i]], y[i]);
        }
        if (hmap1.size() < 3) return -1;

        int res = 0, v1 = 0, v2 = 0, v3 = 0;
        for (auto &[k, v]:hmap1) {
            if (v >= v1) {
                v3 = v2;
                v2 = v1;
                v1 = v;
            } else if (v >= v2) {
                v3 = v2;
                v2 = v;
            } else if (v >= v3) {
                v3 = v;
            }
        }

        return v1+v2+v3;
    }
};