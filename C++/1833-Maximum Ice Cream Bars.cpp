class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cnt(1e5+1, 0);
        for (int cost:costs) {
            cnt[cost]++;
        }

        int res = 0;
        for (int i=1; i<=1e5; i++) {
            if (cnt[i] == 0) continue;
            if (coins < i) break;
            int q = min(coins/i, cnt[i]);
            coins -= q*i;
            res += q;
        }

        return res;
    }
};