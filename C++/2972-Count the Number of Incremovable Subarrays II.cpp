// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-ii/discuss/4448597/Explained-with-dry-run-left-and-right-increasing-seq-oror-simple-and-easy-to-understand
using LL = long long;
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int N = nums.size();
        int rightStart = 0;
        for (int j=N-2; j >=0; j--){
            if (nums[j] >= nums[j+1]){
                rightStart = j+1;  // rightStart: first element of right-side array
                break;
            }
        }

        if (rightStart == 0) return N*(N+1)/2;  // handle the edge case when last element of left-side array
                                                // and first element of right-side array can be the same.
                                                // in this case, if we proceed, we will count N+1 more times
                                                // (N complete arrays and one empty array)
        LL res = N-rightStart+1;

        int prev = -1;
        for (int i=0; i<rightStart; i++){  // i: last element of left-side array
            if (nums[i] <= prev) break;
            while (rightStart < nums.size() && nums[i] >= nums[rightStart]){
                rightStart++;
            }
            prev = nums[i];
            res += (N-rightStart+1);
        }
        return res;
    }
};