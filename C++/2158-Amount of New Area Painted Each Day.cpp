class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, int> hmap; // start:end of each paint
        vector<int> res;
        for (auto &p:paint) {
            int start = p[0], end = p[1];
            auto nxt = hmap.upper_bound(start);
            auto cur = nxt;
            if (nxt != hmap.begin() && prev(nxt)->second >= start) {
                cur = prev(cur);
                start = cur->second;
                cur->second = max(cur->second, end);
            } else {
                hmap.insert({start, end});
                cur = prev(cur);
            }

            int length = end - start;
            if (length <= 0) {
                res.push_back(0);
                continue;
            }
            
            while (nxt != hmap.end() && nxt->first < cur->second) {
                length -= min(nxt->second, cur->second) - (nxt->first);
                cur->second = max(cur->second, nxt->second);
                hmap.erase(nxt++);
            }
            res.push_back(length);
        }
        return res;
    }
};