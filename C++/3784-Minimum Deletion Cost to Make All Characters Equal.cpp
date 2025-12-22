class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long tot = 0;
        unordered_map<char, long long> cnt;

        for (int i=0; i<s.size(); i++) {
            tot += cost[i];
            cnt[s[i]] += cost[i];
        }

        long long res = LLONG_MAX;
        for (auto &[k, v]:cnt) {
            res = min(res, tot-v);
        }

        return res;
    }
};