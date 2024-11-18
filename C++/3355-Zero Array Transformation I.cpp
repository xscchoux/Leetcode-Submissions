class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> diff(N+1);
        for (auto q:queries) {
            int u = q[0], v = q[1];
            diff[u]--;
            diff[v+1]++;
        }

        int running = 0;
        for (int i=0; i<N; i++) {
            running += diff[i];
            if (nums[i] + running > 0) return false;
        }

        return true;
    }
};