class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, longest = 0, N = nums.size();

        vector<pair<int, int>> arr(N);

        for (int i=N-1; i>=0; i--) {
            if (i < N-1 && nums[i] <= nums[i+1]) {
                cnt++;
                arr[i] = {nums[i], cnt};
            } else {
                cnt = 1;
                arr[i] = {nums[i], cnt};
            }
            longest = max(longest, cnt);
        }

        if (longest >= nums.size()-1) return nums.size();

        for (int i=0; i<N; i++) {
            int length = arr[i].second;
            if (i+length == N) {
                longest = max(longest, cnt);
            } else if (i+length+1 == N) {
                longest = max(longest, length+1);
            } else {
                if (nums[i+length+1] >= nums[i+length-1]) {
                    longest = max(longest, length + 1 + arr[i+length+1].second);
                } else {
                    longest = max(longest, length+1);
                }

                if (length >=2 && nums[i+length] >= nums[i+length-2] ) {  // update the last element in first subarray
                    longest = max(longest, length + arr[i+length].second);
                }

            }
        }

        // special case: change first element in subarray
        for (int i=0; i<N-1; i++) {
            if (nums[i] > nums[i+1]) {
                longest = max(longest, 1 + arr[i+1].second);
            }
        }

        return longest;
    }
};