class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> cnt(n);
        for (auto &road:roads) {
            int u = road[0], v = road[1];
            cnt[u]++; cnt[v]++;
        }

        sort(cnt.begin(), cnt.end());
        
        long long res = 0;
        for (int i=0; i<n; i++) {
            res += cnt[i]*(i+1);    
        }

        return res;
    }
};