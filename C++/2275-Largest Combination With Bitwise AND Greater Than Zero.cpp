class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // 10^7 ~ 2^24
        int cnt[25];
        for (int c:candidates) {
            for (int i=0; i<=24; i++) {
                if (c&(1<<i)) {
                    cnt[i]++;
                }
            }
        }
        return *max_element(begin(cnt), end(cnt));
    }
};