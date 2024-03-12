class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> hmap;
        int res = 0, kMod = 1e9+7;
        vector<int> powers;
        int p = 1;
        for (int i=0; i<=21; i++) {
            powers.push_back(p);
            p = 2*p;
        }
        
        for (int d:deliciousness) {
            for (int val:powers) {
                if (hmap.count(val-d)) {
                    res = (res + hmap[val-d])%kMod;
                }
            }
            hmap[d]++;
        }
        
        return res;
    }
};