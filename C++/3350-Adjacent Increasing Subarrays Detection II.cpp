// First AC
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        int window = 1, res = 1;

        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
            while (i+1 >= 2*window && dp[i] >= window && dp[i-window] >= window) {
                res = max(res, window);
                window++;
            }
        }

        return res;
    }
};


// O(1) space, better
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int N = nums.size();
        int preCnt = 0, currCnt = 1, res = 0;

        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                currCnt++;
            } else {
                preCnt = currCnt;
                currCnt = 1;
            }
            res = max(res, min(preCnt, currCnt));
            res = max(res, currCnt/2);
        }

        return res;
    }
};