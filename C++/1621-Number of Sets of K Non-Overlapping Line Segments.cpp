constexpr const int kMod = 1e9+7;
class Solution {
public:
    int numberOfSets(int n, int k) {

        // dp[index][last segement filled][segments]
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(k+1, 0)));
        dp[0][0][0] = 1;

        for (int i=1; i<n; i++) {
            for (int kk=0; kk<=k; kk++) {
                dp[i][0][kk] = (dp[i-1][0][kk] + dp[i-1][1][kk])%kMod;

                dp[i][1][kk] = dp[i-1][1][kk];
                if (kk > 0) {
                    dp[i][1][kk] = (dp[i][1][kk] + dp[i-1][0][kk-1] + dp[i-1][1][kk-1])%kMod;
                }
            }
        }

        return (dp[n-1][1][k] + dp[n-1][0][k])%kMod;
    }
};



// Use combinatorics, very fast but kinda hard (add extra k-1 length-one segments)
using LL = long long;
constexpr int kMod = 1e9+7;

class Solution {
public:
    LL powWithMod(LL a, LL b) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int numberOfSets(int n, int k) {
        // add k-1 segments with length 1
        // choose 2*k points from n+k-1 points, C(n+k-1, 2*k)
        // Two points pair up as a segment. Remove k-1 length-one segments between each pair
        // Note this problem has nothing to do with "stars and bars"

        long long nom = 1, den = 1;

        for (int d = min(2*k, n+k-1-2*k), cnt = 0; d>=1; d--, cnt++) {
            nom = nom*(n+k-1-cnt)%kMod;
            den = den*d%kMod;
        }

        return nom*powWithMod(den, kMod-2)%kMod;

    }
};