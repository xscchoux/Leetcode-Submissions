class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int N = nums.size(), res = 0;

        for (int i=0; i<N; i++) {
            int x = 0, y = 0;
            for (int j=i; j<N; j++) {
                if (nums[j]&1) {
                    y++;
                } else {
                    x++;
                }
                if (b*x <= a*y) {
                    res++;
                }
            }
        }

        return res;
    }
};