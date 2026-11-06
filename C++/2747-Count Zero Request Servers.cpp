class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        map<int, unordered_set<int>> hmap;
        unordered_map<int, int> cnt;

        int N = queries.size();
        vector<int> idx(N);
        for (int i=0; i<N; i++) {
            idx[i] = i;
        }

        for (auto &log:logs) {
            hmap[log[1]].insert(log[0]);
        }

        sort(begin(idx), end(idx), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        int start = max(0, queries[idx[0]]-x), end = queries[idx[0]];

        auto it = hmap.lower_bound(start);
        if (it == hmap.end()) {
            return vector<int>(N, n);
        }

        auto it2 = it;
        while (it2 != hmap.end() && it2->first <= end) {
            for (int key:hmap[it2->first]) {
                cnt[key]++;
            }
            it2++;
        }

        vector<int> res(N, 0);
        res[idx[0]] = n - cnt.size();
        
        for (int k=1; k<idx.size(); k++) {
            int i = idx[k];
            int q = queries[i];
            int qStart = q-x, qEnd = q;

            while (it != hmap.end() && it->first < qStart) {
                for (int key:hmap[it->first]) {
                    cnt[key]--;
                    if (cnt[key] == 0) {
                        cnt.erase(key);
                    }
                }
                it++;
            }
            // note that cnt[key] can be negative here
            while (it2 != hmap.end() && it2->first <= qEnd) {
                for (int key:hmap[it2->first]) {
                    cnt[key]++;
                    if (cnt[key] == 0) {
                        cnt.erase(key);
                    }
                }
                it2++;
            }

            res[i] = n - cnt.size();
        }

        return res;
    }
};