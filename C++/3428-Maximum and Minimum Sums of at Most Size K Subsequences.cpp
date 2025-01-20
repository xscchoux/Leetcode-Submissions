// C(n, r) = C(n-1, r-1) + C(n-1, r)

// Case 1: the n-th item is included in the selection.

// If the n-th item is included, we need to choose the remaining r-1 items from the first n−1 items.
// The number of ways to do this is C(n-1, r-1)

// Case 2: the n-th item is not included in the selection.

// If the n-th item is not included, we need to choose all r items from the first n-1 items.
// The number of ways to do this is C(n-1, r)

using LL = long long;
class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int N = nums.size(), kMod = 1e9+7;
        LL res = 0;

        vector<vector<int>> nCr(N+1, vector<int>(k, 0));
        
        nCr[0][0] = 1;
        for (int n=1; n<N; n++) {
            nCr[n][0] = 1;
            for (int r=1; r<=k-1; r++) {
                nCr[n][r] = (nCr[n-1][r-1] + nCr[n-1][r])%kMod;   // C(n, r) = C(n-1, r-1) + C(n-1, r)
            }
        }

        for (int i=0; i<N; i++) {
            LL subsequence = 1;    // subsequence has only nums[i]
            for (int r=1; r<=min(k-1, i); r++) {
                subsequence = (subsequence + nCr[i][r])%kMod;
            }
            res = (res + (nums[i] + nums[N-i-1])*subsequence)%kMod;
        }

        return res;
    }
};