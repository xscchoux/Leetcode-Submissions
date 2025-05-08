// https://leetcode.cn/problems/find-sum-of-array-product-of-magical-sequences/solutions/3668554/zu-he-shu-xue-ji-yi-hua-sou-suo-by-mipha-sy5x/
using LL = long long;
const int MAX_N = 30;
const int kMod = 1e9+7;

vector<vector<LL>> nCr(MAX_N+1, vector<LL>(MAX_N+1, 0));
int dp[51][31][31][51];

int fillVector = []() {
    // fill nCr
    nCr[0][0] = 1;
    for (int n=1; n<=MAX_N; n++) {
        nCr[n][0] = 1;
        for (int r=1; r<=min(n, r); r++) {
            nCr[n][r] = (nCr[n-1][r] + nCr[n-1][r-1])%kMod;
        }
    }
    return 0;
}();

class Solution {
public:
    int N;
    LL powWithMod(LL a, LL b, int kMod) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int dfs(int idx, int m, int k, int bitLeft, vector<int>& nums) {   // bitLeft: sum of bits from the count of numbers picked from nums[0] ~ nums[idx]
        if (idx == N) {
            if (m == 0) {
                while (bitLeft > 0) {
                    k -= bitLeft&1;
                    bitLeft >>= 1;
                }
                return k==0?1:0;
            }
            return 0;
        }

        if (m == 0) {
            while (bitLeft > 0) {
                k -= bitLeft&1;
                bitLeft >>= 1;
            }
            return k==0?1:0;            
        }

        if (dp[idx][m][k][bitLeft] != -1) return dp[idx][m][k][bitLeft];

        LL res = 0;
        for (int t=0; t<=m; t++) {
            int newBitLeft = bitLeft + t;
            int nk = k - (newBitLeft&1);
            if (nk < 0) continue; 
            res = (res + ((nCr[m][t]*powWithMod(nums[idx], t, kMod))%kMod)*dfs(idx+1, m-t, nk, newBitLeft>>1, nums))%kMod;
        }

        return dp[idx][m][k][bitLeft] = res;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        this->N = nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, m, k, 0, nums);
    }
};