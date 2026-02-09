class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int N1 = nums1.size(), N2 = nums2.size();
        vector<vector<vector<long long>>> dp(N1+1, vector<vector<long long>>(N2+1, vector<long long>(k+1, LLONG_MIN/2)));
        
        for (int i=0; i<=N1; i++) {
            for (int j=0; j<=N2; j++) {
                dp[i][j][0] = 0;
            }
        }

        // dp[i][j][k] = min(dp[i-1][j-1][k-1] + nums1[i]*nums2[j], dp[i][j-1][k], dp[i-1][j][k])

        for (int i=0; i<N1; i++) {
            for (int j=0; j<N2; j++) {
                const long long v = 1LL*nums1[i]*nums2[j];
                for (int kk=1; kk<=i+1 && kk <= j+1 && kk<=k; kk++) {
                    dp[i+1][j+1][kk] = max({dp[i][j][kk-1] + v, dp[i+1][j][kk], dp[i][j+1][kk]});
                }
            }
        }

        return dp[N1][N2][k];
    }
};


// space optimization
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int N1 = nums1.size(), N2 = nums2.size();
        vector<vector<long long>> prev(N1+1, vector<long long>(N2+1, 0)), curr(N1+1, vector<long long>(N2+1, LLONG_MIN/2));

        // dp[i][j][k] = min(dp[i-1][j-1][k-1] + nums1[i]*nums2[j], dp[i][j-1][k], dp[i-1][j][k])

        for (int kk=1; kk<=k; kk++) {
            for (int i=0; i<=N1; i++) {
                fill(curr[i].begin(), curr[i].end(), LLONG_MIN/2);
            }

            for (int i=0; i<N1; i++) {
                for (int j=0; j<N2; j++) {
                    const long long v = 1LL*nums1[i]*nums2[j];
                    curr[i+1][j+1] = max(curr[i+1][j+1], curr[i][j+1]);
                    curr[i+1][j+1] = max(curr[i+1][j+1], curr[i+1][j]);
                    curr[i+1][j+1] = max(curr[i+1][j+1], prev[i][j] + v);
                }
            }
            swap(prev, curr);
        }

        return prev[N1][N2];
    }
};