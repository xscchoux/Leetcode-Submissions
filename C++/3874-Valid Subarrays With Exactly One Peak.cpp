class Solution {
public:
    long long validSubarrays(vector<int>& nums, int k) {
        vector<int> peakIdx;
        for (int i=1; i<nums.size()-1; i++) {
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                peakIdx.push_back(i);
            }
        }

        long long res = 0;
        for (int i=0; i<peakIdx.size(); i++) {
            int left = ((i==0)?peakIdx[i]:(peakIdx[i] - peakIdx[i-1]-1));
            int right = (i == (peakIdx.size()-1))?(nums.size()-1-peakIdx[i]):(peakIdx[i+1]-peakIdx[i]-1);
            left = min(left, k);
            right = min(right, k);
            res += (long long)(left+1)*(right+1);
        }

        return res;
    }
};