class Solution {
public:
    long long getProduct(long long a, long long b) {
        if (a > LLONG_MAX / b)
            return LLONG_MAX;
        return a * b;
    }
    int smallestBalancedIndex(vector<int>& nums) {
        int N = nums.size();
        long long leftSum = 0;

        vector<long long> rightProduct(N, 1);
        for (int i=N-2; i>=0; i--) {
            rightProduct[i] = getProduct(rightProduct[i+1], nums[i+1]);
        }

        for (int i=0; i<N; i++) {
            if (leftSum == rightProduct[i]) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};