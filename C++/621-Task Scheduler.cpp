class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> hmap;
        for (char c:tasks) {
            hmap[c]++;
        }
        
        unordered_map<char, int> pos;
        for (auto &kv:hmap) pos[char(kv.first)] = -1-n;
        int t = 0;
        
        while (!hmap.empty()) {
            char curr;
            int maxFreq = 0;
            int maxDist = 0;
            
            for (auto &kv:hmap) {
                if (maxDist <= n && t - pos[char(kv.first)] >= maxDist) {
                    if (t-pos[char(kv.first)] > maxDist) {
                        maxFreq = kv.second;
                        curr = kv.first;
                    }
                    else if (t-pos[char(kv.first)] == maxDist && kv.second > maxFreq) {
                        maxFreq = kv.second;
                        curr = kv.first;
                    }
                    maxDist = min(t - pos[char(kv.first)], n+1);
                    
                } else if (t - pos[char(kv.first)] >= n+1 ) {
                    if (maxFreq < kv.second) {
                        maxFreq = kv.second;
                        curr = kv.first;
                    }
                }
            }

            hmap[curr]--;
            t = max(pos[curr] + n + 1, t);
            
            pos[curr] = t;
            if (hmap[curr] == 0) {
                hmap.erase(curr);
            }
            t++;
            
        }
        
        return t;
    }
};