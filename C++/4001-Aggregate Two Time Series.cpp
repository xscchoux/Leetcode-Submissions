class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        unordered_map<int, int> hmap1, hmap2;
        set<int, greater<>> key;

        for (auto &s:series1) {
            hmap1[s[0]] = s[1];
            key.insert(s[0]);
        }

        for (auto &s:series2) {
            hmap2[s[0]] = s[1];
            key.insert(s[0]);
        }

        vector<vector<int>> res;
        int val1 = 0, val2 = 0;
        for (int num:key) {
            if (hmap1.contains(num)) {
                val1 = hmap1[num];
            }
            if (hmap2.contains(num)) {
                val2 = hmap2[num];
            }
            res.push_back({num, val1+val2});
        }
        sort(begin(res), end(res));
        return res;
    }
};


// O(N)
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int idx1 = 0, idx2 = 0, N1 = series1.size(), N2 = series2.size();
        vector<vector<int>> res;

        while (idx1 < N1 && idx2 < N2) {
            int sum = series1[idx1][1] + series2[idx2][1];
            int k1 = series1[idx1][0], k2 = series2[idx2][0];
            if (k1 < k2) {
                res.push_back({k1, sum});
                idx1++;
            } else if (k1 > k2) {
                res.push_back({k2, sum});
                idx2++;
            } else {
                res.push_back({k1, sum});
                idx1++;idx2++;
            }
        }

        while (idx1<N1) {
            res.push_back({series1[idx1]});
            idx1++;
        }

        while (idx2<N2) {
            res.push_back({series2[idx2]});
            idx2++;
        }        

        return res;
    }
};