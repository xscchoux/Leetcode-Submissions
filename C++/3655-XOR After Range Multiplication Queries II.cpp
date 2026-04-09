//  Square Root Decomposition + Difference Array
// https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/editorial/
using LL = long long;
const int kMod = 1e9+7;
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
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), sqrtN = sqrt(N);

        vector<vector<tuple<int, int, int>>> kGroup(sqrtN);

        // O(N*sqrt(N))
        for (auto &q:queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < sqrtN) {
                kGroup[k].push_back({l, r, v});
            } else {
                for (int i=l; i<=r; i+=k) {
                    nums[i] = 1ll*nums[i]*v%kMod;
                }
            }
        }

        // O(N*sqrt(N))
        vector<LL> diff(N+sqrtN);
        for (int k=0; k<sqrtN; k++) {
            if (kGroup[k].empty()) continue;
            
            // difference array
            fill(begin(diff), end(diff), 1);
            for (auto &q:kGroup[k]) {
                int l = get<0>(q), r = get<1>(q), v = get<2>(q);
                diff[l] = diff[l]*v%kMod;
                int R = ((r-l)/k + 1)*k + l;
                diff[R] = diff[R]*powWithMod(v, kMod-2)%kMod;
            }

            // compute cumulative multiplier for each position
            for (int i=k; i<N; i++) {
                diff[i] = diff[i]*diff[i-k]%kMod;
            }

            for (int i=0; i<N; i++) {
                nums[i] = 1ll*nums[i]*diff[i]%kMod;
            }
        }

        int res = 0;
        for (int i=0; i<N; i++) {
            res ^= nums[i];
        }

        return res;
    }
};