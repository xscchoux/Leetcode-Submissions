class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int allGCD = 0;  // note this trick

        int oneCnt = 0;
        for (int i=0; i<N; i++) {
            if (nums[i] == 1) oneCnt++;
            allGCD = gcd(allGCD, nums[i]);
        }

        if (allGCD != 1) return -1;

        if (oneCnt > 0) return N - oneCnt;

        for (int length=2; length<=N; length++) {
            for (int start=0; start<N; start++) {
                int end = start+length-1;
                if (end >= N) break;
                int gcdVal = 0;
                for (int curr=start; curr<=end; curr++) {
                    gcdVal = gcd(gcdVal, nums[curr]);
                }
                if (gcdVal == 1) {
                    return N-1 + end-start;
                }
            }
        }

        return 0;
    }
};