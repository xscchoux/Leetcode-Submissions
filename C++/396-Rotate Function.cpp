// first AC
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefixSum(N, 0), suffixSum(N, 0);
        for (int i=0; i<N; i++) {
            if (i == 0) {
                prefixSum[i] = nums[i];
                suffixSum[N-i-1] = nums[N-i-1];
            } else {
                prefixSum[i] = prefixSum[i-1] + nums[i];
                suffixSum[N-i-1] = suffixSum[N-i] + nums[N-i-1];
            }
        }

        int curr = 0;
        for (int i=0; i<N; i++) {
            curr += i*nums[i];
        }
        
        int res = curr;
        for (int i=N-1; i>=1; i--) {
            curr -= (N-1)*nums[i];
            curr += prefixSum[i-1] + (i==(N-1)?0:suffixSum[i+1]);
            res = max(res, curr);
        }

        return res;
    }
};




class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int N = nums.size();
        int tot = accumulate(begin(nums), end(nums), 0);

        int curr = 0;
        for (int i=0; i<N; i++) {
            curr += i*nums[i];
        }

        int res = curr;
        for (int i=N-1; i>=1; i--) {
            curr -= N*nums[i];
            curr += tot;
            res = max(curr, res);
        }

        return res;
    }
};