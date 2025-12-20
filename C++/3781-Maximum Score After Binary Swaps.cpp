class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long res = 0;
        priority_queue<int> pq;
        int N = nums.size();

        for (int i=0; i<N; i++) {
            pq.push(nums[i]);
            if (s[i] == '1') {
                res += pq.top();
                pq.pop();
            }
        }

        return res;
    }
};