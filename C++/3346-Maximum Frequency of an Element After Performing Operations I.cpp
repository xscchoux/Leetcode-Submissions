class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> cnt;
        for (int num:nums) {
            cnt[num]++;
        }

        int res = 0;
        for (int i=nums[0]; i<=nums.back(); i++) {
            int leftIdx = lower_bound(nums.begin(), nums.end(), i-k) - nums.begin();
            int rightIdx = upper_bound(nums.begin(), nums.end(), i+k) - nums.begin();
            res = max(res, cnt[i] + min(numOperations, rightIdx-leftIdx-cnt[i]));
        }

        return res;
    }
};


// clever O(max value in nums) solution without using binary search, kinda hard
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int N = nums.size();
        int mn = INT_MAX, mx = *max_element(begin(nums), end(nums));
        const int sz = mx+2;
        vector<int> cnt(sz, 0), freq(sz, 0);

        for (int num:nums) {
            freq[num]++;
            int leftBound = max(1, num-k);
            int rightBound = min(num+k+1, mx+1);
            cnt[leftBound]++;
            cnt[rightBound]--;
            mn = min(mn, leftBound);
        }

        int curr = 0, res = 0;
        for (int num=mn; num<=mx; num++) {
            curr += cnt[num];
            res = max(res, freq[num] + min(numOperations, curr-freq[num]) );
        }
        
        return res;
    }
};