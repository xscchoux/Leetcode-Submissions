// binary search + median
class Solution {
public:
    bool isOK(vector<int>& nums, vector<long>& preSum, int length, long long k, int N){
        for (int i=0; i+length-1<N; i++){
            int j = i+length-1;
            long median = (i+j)/2;
            long toIncrease = nums[median]*(median-i+1) - (preSum[median+1] - preSum[i]);
            long toDecrease = (preSum[j+1] - preSum[median]) - nums[median]*(j+1-median);
            if (toIncrease+toDecrease <= k) return true;
        }
        return false;
    }
    
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<long> preSum(N+1, 0);
        for (int i=0; i<N; i++){
            preSum[i+1] = preSum[i] + nums[i];
        }

        int left = 1, right = N;
        while (left + 1 < right){
            int mid = left + (right - left)/2;
            if (isOK(nums, preSum, mid, k, N)){
                left = mid;
            } else {
                right = mid;
            }
        }
        if (isOK(nums, preSum, right, k, N)) return right;
        return left;
    }
};



// sliding window + median
class Solution {
public:
    bool isOK(vector<int>& nums, vector<long>& preSum, int i, int j, long long k){
        long median = (i+j)/2;
        long toIncrease = nums[median]*(median-i+1) - (preSum[median+1] - preSum[i]);
        long toDecrease = (preSum[j+1] - preSum[median]) - nums[median]*(j+1-median);
        return toIncrease + toDecrease <= k;
    }
    
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int N = nums.size(), res = 0;
        vector<long> preSum(N+1, 0);
        for (int i=0; i<N; i++){
            preSum[i+1] = preSum[i] + nums[i];
        }

        int j = 0;
        for (int i=0; i<N; i++){
            while (j<N && isOK(nums, preSum, i, j, k)){
                res = max(res, j-i+1);
                j++;
            }
        }
        return res;
    }
};