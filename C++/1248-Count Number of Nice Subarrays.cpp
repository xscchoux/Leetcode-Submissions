class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int N = nums.size();

        vector<int> cnt(N+1, 0);
        cnt[0] = 1;
        int curr = 0, res = 0;
        for (int i=0; i<N; i++) {
            if (nums[i]%2 == 1) curr++;
            cnt[curr]++;
            if (curr-k>=0) {
                res += cnt[curr-k];
            }
        }

        return res;
    }
};