// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/solutions/6822077/multiset/
using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp(N+1, 0); // the number of ways to partition the first i elements (i.e. nums[0:i]). 
        dp[0] = 1;     // edge case: dp[0] = 1 (there's only one way to parititon an empty array)
        int left = 0;  // left bound of max segment
        multiset<int> ms;  // nums inside current max segment
        LL totPartitions = 0;   // when current max segment extends to index left. range of max segment: nums[left:i+1], totPartitions is dp[left]+dp[left+1]+...+dp[i]

        for (int i=0; i<N; i++) {
            totPartitions = (totPartitions + dp[i])%kMod;
            ms.insert(nums[i]);
            while (*prev(end(ms)) - *begin(ms) > k) {
                totPartitions = (totPartitions - dp[left] + kMod)%kMod;
                ms.erase(ms.find(nums[left]));
                left++;
            }
            dp[i+1] = totPartitions;
        }

        return dp.back();
    }
};


// Faster
// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/solutions/6821862/java-c-python-mono-deque-dp/
// Also check Huifeng Guan's video
using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> dp(N+1, 0); // the number of ways to partition the first i elements (i.e. nums[0:i]). 
        dp[0] = 1;  // edge case: dp[0] = 1 (there's only one way to parititon an empty array)
        int left = 0;  // left bound of current segment
        LL totPartitions = 0;  // when current max segment extends to index left. range of max segment: nums[left:i+1], totPartitions is dp[left]+dp[left+1]+...+dp[i]
        deque<int> monoInc, monoDec;

        for (int i=0; i<N; i++) {
            totPartitions = (totPartitions + dp[i])%kMod;
            while (!monoInc.empty() && nums[i] <= nums[monoInc.back()]) {
                monoInc.pop_back();
            }
            monoInc.push_back(i);
            while (!monoDec.empty() && nums[i] >= nums[monoDec.back()]) {
                monoDec.pop_back();
            }
            monoDec.push_back(i);
            while (nums[monoDec.front()] - nums[monoInc.front()] > k) {
                totPartitions = (totPartitions - dp[left] + kMod)%kMod;
                if (monoDec.front() == left) monoDec.pop_front();
                if (monoInc.front() == left) monoInc.pop_front();
                left++;
            }
            dp[i+1] = totPartitions;
        }

        return dp.back();
    }
};


// Redo
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> preSum(N+1, 0), dp(N+1, 0);
        preSum[0] = 1;
        dp[0] = 1;
        multiset<int> ms;
        int left = 0, res = 0, kMod = 1e9+7;

        for (int i=0; i<N; i++) {
            ms.insert(nums[i]);
            while (*ms.rbegin() - *ms.begin() > k) {
                ms.erase(ms.find(nums[left]));
                left++;
            }
            // dp[i] = dp[i-1] + dp[i-2] + ... + dp[left-1]
            //       = preSum[i-1] - preSum[left-2]
            dp[i+1] = (preSum[i] - (left-1<0?0:preSum[left-1]) + kMod)%kMod;        
            preSum[i+1] = (preSum[i] + dp[i+1])%kMod;
        }

        return dp[N];
    }
};