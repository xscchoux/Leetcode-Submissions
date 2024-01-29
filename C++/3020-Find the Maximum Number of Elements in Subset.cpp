class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> hmap;
        for (int num:nums) {
            hmap[num]++;
        }
        
        int res = hmap[1];
        if (res%2 == 0) res--;
        
        for (auto &kv:hmap) {
            long key = kv.first;
            int value = kv.second;
            if (key == 1) continue;

            int cnt = 0;
            while (key <= INT_MAX && hmap.find(key) != hmap.end()) {
                if (hmap[key] >= 2) cnt+=2;
                else {
                    cnt += 1;
                    break;
                }
                key *= key;
            }
            if (cnt%2 == 0) cnt--;
            res = max(cnt, res);
        }
        
        return res;
    }
};