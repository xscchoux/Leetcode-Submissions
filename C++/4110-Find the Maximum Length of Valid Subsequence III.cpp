class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> length(k, 0);

        for (int i=0; i<N; i++) {
            int rem = nums[i]%k, pairRem = (k-rem)%k;
            if (length[pairRem] == 0) {
                length[rem] = 1;
            } else {
                length[rem] = 1 + length[pairRem];
            }
        }

        return *max_element(begin(length), end(length));
    }
};