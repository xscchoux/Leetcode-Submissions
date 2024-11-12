// map + binary search
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> hmap;
        int val = 1;
        for (auto &item:items) {
            val = max(val, item[1]);
            hmap[item[0]] = max(hmap[item[0]], val);
        }
        vector<int> res;
        for (int q:queries) {
            auto it = hmap.upper_bound(q);
            if (it == hmap.begin()) {
                res.push_back(0);
            } else {
                advance(it, -1);
                res.push_back(it->second);
            }
        }
        return res;
    }
};


// sorting + two pointer, better
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> qPair;
        for (int i=0; i<queries.size(); i++) {
            qPair.push_back({queries[i], i});
        }
        sort(begin(qPair), end(qPair));

        vector<int> res(queries.size());
        int val = 0, itemIdx = 0;

        for (auto [q, idx]:qPair) {
            while (itemIdx < items.size() && q >= items[itemIdx][0]) {
                val = max(val, items[itemIdx][1]);
                itemIdx++;
            }
            res[idx] = val;
        }

        return res;
    }
};