class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int N = nums.size();
        int mnPos = min_element(begin(nums), end(nums)) - begin(nums);
        int mxPos = max_element(begin(nums), end(nums)) - begin(nums);
        
        int left = min(mnPos, mxPos), right = max(mnPos, mxPos);
        int res = min({right+1, left+1+N-right, N-left});

        return res;
    }
};