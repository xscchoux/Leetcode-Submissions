// prefix sum + binary search
using LL = long long;
class Solution {
public:
    int bs(int idx, vector<LL>& preSum, int k, vector<int>& nums){
        int left = 0, right = idx;
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (k >= (LL)nums[idx]*(idx-mid) - (preSum[idx]-preSum[mid]) ){
                right = mid;
            } else {
                left = mid;
            }
        }

        if (k >= (LL)nums[idx]*(idx-left) - (preSum[idx]-preSum[left])) return left;
        return right;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<LL> preSum(N+1, 0);
        preSum[1] = nums[0];
        int res = 1;
        
        for (int i = 1; i < N; i++){
            preSum[i+1] = nums[i] + preSum[i];
            int prevIdx = bs(i, preSum, k, nums);
            res = max(res, i-prevIdx+1);
            
        }
        return res;
    }
};


// sliding window

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int freq = 1;
        long curr = 0;
        int left = 0;
        for (int i=0; i<nums.size(); i++){
            curr += nums[i];
            while ((i-left+1)*(long)nums[i] - curr > k){
                curr -= nums[left];
                left++;
            }
            freq = max(freq, i-left+1);
        }
        return freq;
    }
};