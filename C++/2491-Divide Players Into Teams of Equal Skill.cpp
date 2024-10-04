class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int N = skill.size(), tot = 0;
        unordered_map<int, int> hmap;
        
        for (int s:skill) {
            tot += s;
            hmap[s]++;
        }

        tot = tot/(N/2);

        long long res = 0;
        for (auto &[k, v]:hmap) {
            int pairSkill = tot-k;
            if (!hmap.contains(pairSkill) || hmap[pairSkill] != hmap[k]) return -1;
            res += (long long)hmap[k]*k*pairSkill;
        }

        return res/2;
    }
};