class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> arr;
        int N = labels.size();
        for (int i=0; i<N; i++) {
            arr.push_back({values[i], labels[i]});
        }
        sort(arr.begin(), arr.end(), greater<>());

        unordered_map<int, int> cnt;

        int res = 0;
        for (auto &[val, label]:arr) {
            if (cnt[label] == useLimit) continue;
            cnt[label]++;
            res += val;
            if (--numWanted == 0) break;
        }

        return res;
    }
};