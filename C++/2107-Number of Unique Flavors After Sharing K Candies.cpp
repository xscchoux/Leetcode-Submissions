class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> cnt;
        int N = candies.size(), res = 0;
        for (int num:candies) cnt[num]++;
        if (k == 0) return cnt.size();
        for (int i=0; i<N; i++) {
            cnt[candies[i]]--;
            if (cnt[candies[i]] == 0) cnt.erase(candies[i]);
            if (i>=k) cnt[candies[i-k]]++;
            if (i>=k-1) res = max(res, (int)cnt.size());
        }
        return res;
    }
};