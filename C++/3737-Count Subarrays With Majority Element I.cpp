class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int N = nums.size(), res = 0;

        for (int i=0; i<N; i++) {
            for (int j=i, cnt =0; j<N; j++) {
                cnt += (nums[j] == target);
                if ((j-i+1) < 2*cnt) {
                    res++;
                }
            }
        }

        return res;
    }
};