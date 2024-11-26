class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int N = nums.size();
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(op1+1, vector<int>(op2+1, INT_MAX/2)));
        dp[0][0][0] = 0;

        for (int i=0; i<N; i++) {
            // no ops
            for (int cnt1=0; cnt1<=op1; cnt1++) {
                for (int cnt2=0; cnt2<=op2; cnt2++) {
                    if (dp[i][cnt1][cnt2] < INT_MAX/2) dp[i+1][cnt1][cnt2] = min(dp[i+1][cnt1][cnt2], dp[i][cnt1][cnt2] + nums[i]);
                }
            }            

            // op1 only
            for (int cnt1=0; cnt1<op1; cnt1++) {
                for (int cnt2=0; cnt2<=op2; cnt2++) {
                    if (dp[i][cnt1][cnt2] < INT_MAX/2) dp[i+1][cnt1+1][cnt2] = min(dp[i+1][cnt1+1][cnt2], dp[i][cnt1][cnt2] + (nums[i]+1)/2);
                }
            }
            // op2 only
            if (nums[i] >= k) {
                for (int cnt2=0; cnt2<op2; cnt2++) {
                    for (int cnt1=0; cnt1<=op1; cnt1++) {
                        if (dp[i][cnt1][cnt2] < INT_MAX/2) dp[i+1][cnt1][cnt2+1] = min(dp[i+1][cnt1][cnt2+1], dp[i][cnt1][cnt2] + nums[i]-k);
                    }
                }       
            }

            // op2 then op1
            if (nums[i] >= k) {
                for (int cnt2=0; cnt2<op2; cnt2++) {
                    for (int cnt1=0; cnt1<op1; cnt1++) {
                        if (dp[i][cnt1][cnt2] < INT_MAX/2) dp[i+1][cnt1+1][cnt2+1] = min(dp[i+1][cnt1+1][cnt2+1], dp[i][cnt1][cnt2] + (nums[i]-k+1)/2 );
                    }
                }       
            }

            // op1 then op2
            if ( (nums[i]+1)/2 >= k) {
                for (int cnt2=0; cnt2<op2; cnt2++) {
                    for (int cnt1=0; cnt1<op1; cnt1++) {
                        if (dp[i][cnt1][cnt2] < INT_MAX/2) dp[i+1][cnt1+1][cnt2+1] = min(dp[i+1][cnt1+1][cnt2+1], dp[i][cnt1][cnt2] + (nums[i]+1)/2 - k );
                    }
                }       
            }
        }

        int res = accumulate(begin(nums), end(nums), 0);
        for (int cnt1=0; cnt1<=op1; cnt1++) {
            for (int cnt2=0; cnt2<=op2; cnt2++) {
                res = min(res, dp[N][cnt1][cnt2]);
            }
        }

        return res;
    }
};