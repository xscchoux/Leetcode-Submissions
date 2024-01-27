class Solution {
public:
    int N;
    int dfs(int idx, long bitmask, vector<pair<long, int>>& bitMap) {
        if (idx == N) return 0;
        // pass
        int res = dfs(idx+1, bitmask, bitMap);
        // add
        if ( (bitmask&bitMap[idx].first) == 0) {
            res = max(res, bitMap[idx].second + dfs(idx+1, bitmask|bitMap[idx].first, bitMap) );
        }
        return res;
    }
    
    int maxLength(vector<string>& arr) {
        vector<pair<long, int>> bitMap;
        for (string s:arr) {
            long bit = 0;
            bool qualified = true;
            for (char c:s) {
                if ( (bit & (1 << (c-'a'))) != 0) {
                    qualified = false;
                    break;
                }
                bit |= 1 << (c-'a');
            }
            if (qualified) bitMap.push_back({bit, s.size()});
        }
        this->N = bitMap.size();
        
        return dfs(0, 0, bitMap);
    }
};