// Need to reverse the Array to use handling a monotonic decreasing stack while iterating forward.
using LL = long long;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        reverse(begin(nums), end(nums));
        LL res = 0, cost = 0;
        int left = 0, N = nums.size();
        deque<int> dq;  // monotonically decreasing stack

        for (int curr = 0; curr<N; curr++) {
            // keep dq a monotonically decreasing stack. Calculate the cost.
            while (!dq.empty() && nums[curr] > nums[dq.back()]) {
                int dqIdx = dq.back();
                dq.pop_back();
                int prev = dq.empty()?left-1:dq.back();
                cost += (LL)(nums[curr]-nums[dqIdx])*(dqIdx-prev);
            }
            dq.push_back(curr);
            // if cost > k, increase left index
            while (cost > k) {
                cost -= nums[dq.front()] - nums[left];
                if (dq.front() == left) {
                    dq.pop_front();
                }
                left++;
            }
            res += curr-left+1;
        }
        return res;
    }
};