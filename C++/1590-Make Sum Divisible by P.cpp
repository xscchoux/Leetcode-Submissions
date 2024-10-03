// My first try (binary search)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int N = nums.size();
        unordered_map<int, vector<int>> preSum;

        int running = 0;
        preSum[0].push_back(-1);
        for (int i=0; i<N; i++) {
            running = (running + nums[i])%p;
            preSum[running].push_back(i);
        }

        int length = N; // length of subarray that needs to be removed
        if (!preSum[0].empty()) length = N - (preSum[0].back() + 1);

        running = 0;
        for (int i=N-1; i>=0; i--) {
            running = (running + nums[i])%p;
            int pairVal = (p-running)%p;
            if (preSum[pairVal].empty()) continue;
            auto it = lower_bound(begin(preSum[pairVal]), end(preSum[pairVal]), i);
            if (it == preSum[pairVal].begin()) continue;
            it--;
            int preInd = *it;
            length = min(length, N-(preInd+1)-(N-i));
        }

        return length==N?-1:length;
    }
};


// Need kinda complex algebra
// https://leetcode.com/problems/make-sum-divisible-by-p/solutions/859173/detailed-explanation-of-math-behind-o-n-solution/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int N = nums.size();
        int tot = 0;

        for (int num:nums) tot = (tot+num)%p;
        if (tot == 0) return 0;

        unordered_map<int, int> hmap; // previous mod:index
        hmap[0] = -1;
        int running = 0;
        int res = N;
        for (int i=0; i<N; i++) {
            running = (running + nums[i])%p;
            int val = (running-tot+p)%p;
            if (hmap.contains(val)) {
                res = min(res, i-hmap[val]);
            }
            hmap[running] = i;
        }

        return res == N?-1:res;
    }
};