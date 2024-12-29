// first AC
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int N = nums.size(), res = INT_MIN;
        vector<int> leftMax(N, 0);
        int prev = 0;
        for (int i=0; i<N; i++) {
            leftMax[i] = prev;
            prev = max(0, nums[i]+prev);
        }

        vector<int> rightMax(N, 0);
        prev = 0;
        for (int i=N-1; i>=0; i--) {
            rightMax[i] = prev;
            prev = max(0, nums[i]+prev);
        }

        for (int i=0; i<N; i++) {
            res = max(res, nums[i]*nums[i] + leftMax[i] + rightMax[i]);
        }

        return res;
    }
};


// better
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int N = nums.size(), res = INT_MIN;
        vector<int> leftMax(N, 0);
        int prev = 0;
        for (int i=0; i<N; i++) {
            leftMax[i] = prev;
            prev = max(0, nums[i]+prev);
        }

        vector<int> rightMax(N, 0);
        prev = 0;
        for (int i=N-1; i>=0; i--) {
            rightMax[i] = prev;
            res = max(res, leftMax[i] + nums[i]*nums[i] + rightMax[i]);
            prev = max(0, nums[i]+prev);
        }

        return res;
    }
};