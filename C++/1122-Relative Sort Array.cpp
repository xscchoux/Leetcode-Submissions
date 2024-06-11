class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> cnt;
        for (int num:arr1) cnt[num]++;

        vector<int> res;

        for (int num:arr2) {
            for (int i=0; i<cnt[num]; i++) {
                res.push_back(num);
            }
            cnt.erase(num);
        }

        vector<int> remain;

        for (auto &kv:cnt) {
            for (int i=0; i<kv.second; i++) {
                remain.push_back(kv.first);
            }
        }

        sort(remain.begin(), remain.end());
        res.insert(res.end(), remain.begin(), remain.end());

        return res;
    }
};