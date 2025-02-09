class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int N = nums.size(), op = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long curr = 0;

        for (int i=0; i<N; i++) {
            curr += nums[i];
            if (nums[i] < 0) {
                pq.push(nums[i]);
                while (curr < 0) {
                    curr -= pq.top();
                    pq.pop();
                    op++;
                }
            }
        }

        return op;
    }
};