class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int N = nums.size();
        long long resL = 1;
        for (int k=0; k<N; k++) {
            resL = lcm(resL, nums[k]);
        }

        long long resG = nums[0];
        for (int k=1; k<N; k++) {
            resG = gcd(resG, nums[k]);
        }

        long long res = resL*resG;
        if (N == 1) return res;
        for (int i=0; i<N; i++) {
            long long l = 1;
            for (int j=0; j<N; j++) {
                if (j == i) continue;
                l = lcm(l, nums[j]);
            }
            long long g = nums[(i+1)%N];
            for (int j=0; j<N; j++) {
                if (j == i) continue;
                g = gcd(g, nums[j]);
            }
            res = max(res, l*g);
        }
        return res;
    }
};