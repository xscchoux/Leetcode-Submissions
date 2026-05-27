class Solution {
public:
    int minOperations(vector<int>& nums) {
        int lowIdx = 0, lowVal = nums[0], N = nums.size();
        if (N == 1) return 0;

        for (int i=0; i<N; i++) {
            if (nums[i] < lowVal) {
                lowVal = nums[i];
                lowIdx = i;
            }
        }

        // traverse left
        bool sortedLeftwise = true;
        int currIdx = (lowIdx-1+N)%N, prevIdx = lowIdx;
        while (currIdx != lowIdx) {
            if (nums[currIdx] <= nums[prevIdx]) {
                sortedLeftwise = false;
                break;
            }
            currIdx = (currIdx-1+N)%N;
            prevIdx = (prevIdx-1+N)%N;
        }

        // traverse right
        bool sortedRightwise = true;
        currIdx = (lowIdx+1+N)%N;
        prevIdx = lowIdx;
        while (currIdx != lowIdx) {
            if (nums[currIdx] <= nums[prevIdx]) {
                sortedRightwise = false;
                break;
            }
            currIdx = (currIdx+1+N)%N;
            prevIdx = (prevIdx+1+N)%N;
        }

        if (!sortedLeftwise && !sortedRightwise) return -1;

        int res = INT_MAX;
        if (sortedRightwise) {
            res = min(lowIdx, 1+(N-1-lowIdx)+1+1);  // (reverse) + (move the lowIdx to 0) + (move the lowIdx to N-1) + (reverse again)
        } else {
            res = min(1+(N-1-lowIdx), 1+lowIdx+1);
        }

        return res;
    }
};