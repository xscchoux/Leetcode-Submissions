class Solution {
public:
    int cal(int a, int b) {
        if ((a%2)^(b%2)) {
            return 1;
        } else {
            return 2;
        }
    }
    int minLargest(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j][0] = min( next odd/even num of dp[i-1][j][0], next odd/even num of dp[i-1][j][1]), fill nums1[i], nums1[i] is current max
        // dp[i][j][1] = min( next odd/even num of dp[i][j-1][0], next odd/even num of dp[i][j-1][1]), fill nums2[j], nums2[j] is current max
        int N1 = nums1.size(), N2 = nums2.size();
        vector<vector<vector<int>>> dp(N1+1, vector<vector<int>>(N2+1, vector<int>(2, INT_MAX/2)));
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;

        for (int i=0; i<=N1; i++) {
            for (int j=0; j<=N2; j++) {
                // add to nums1
                if (i > 0) dp[i][j][0] = min( dp[i-1][j][0] + cal(dp[i-1][j][0], nums1[i-1]), dp[i-1][j][1] + cal(dp[i-1][j][1], nums1[i-1]) );
                // add to nums2
                if (j > 0) dp[i][j][1] = min( dp[i][j-1][0] + cal(dp[i][j-1][0], nums2[j-1]), dp[i][j-1][1] + cal(dp[i][j-1][1], nums2[j-1]) );
            }
        }

        return min({dp[N1][N2][0], dp[N1][N2][1]});
    }
};



// Better
class Solution {
public:
    int cal(int a, int b) {
        if ((a%2)^(b%2)) {
            return 1;
        } else {
            return 2;
        }
    }
    int minLargest(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]: current max value considering the first i elements for nums1, the first j elements for nums2
        // dp[i][j] = min( next odd/even num of dp[i-1][j]), fill nums1[i]
        // dp[i][j] = min( next odd/even num of dp[i][j-1]), fill nums2[j]
        int N1 = nums1.size(), N2 = nums2.size();
        vector<vector<int>> dp(N1+1, vector<int>(N2+1, INT_MAX/2));
        dp[0][0] = 0;

        for (int i=0; i<=N1; i++) {
            for (int j=0; j<=N2; j++) {
                // add to nums1
                if (i > 0) dp[i][j] = dp[i-1][j] + cal(dp[i-1][j], nums1[i-1]);
                // add to nums2
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + cal(dp[i][j-1], nums2[j-1]));
            }
        }

        return dp[N1][N2];
    }
};