constexpr const int kMod = 1e9 + 7;
bool flag = false;
int cnt[801];
void fillCnt() {
    for (int i=2; i<801; i++) {
        cnt[i] = 1 + cnt[__builtin_popcount(i)];
    }
}

class Solution {
public:
    int N, dp[801][801][2];
    int dfs(int idx, int setBits, int tight, string& s, int k) {
        if (idx == N) {
            // Note that we use cnt[setBits] >= k instead of cnt[setBits] > k here.
            // This is because we need one more step: setBits = __builtin_popcount(number)
            if (tight || cnt[setBits] >= k) return 0;
            return 1;
        }
        if (dp[idx][setBits][tight] != -1) return dp[idx][setBits][tight];

        int res;
        if (tight) {
            if (s[idx] == '0') {
                res = dfs(idx+1, setBits, 1, s, k)%kMod;
            } else {
                res = (dfs(idx+1, setBits, 0, s, k)+dfs(idx+1, setBits+1, 1, s, k))%kMod;
            }
            return dp[idx][setBits][tight] = res;
        }

        res = (dfs(idx+1, setBits, 0, s, k) + dfs(idx+1, setBits+1, 0, s, k))%kMod;

        return dp[idx][setBits][tight] = res;
    }

    int countKReducibleNumbers(string s, int k) {
        N = s.size();
        memset(dp, -1, sizeof(dp));
        if (!flag) {
            fillCnt();
            flag = true;
        }
        return dfs(0, 0, 1, s, k)-1; // remove the case when all bits are zero
    }
};