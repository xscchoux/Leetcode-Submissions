// https://leetcode.com/problems/count-frequency-staircase-subarrays-i/
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int N = nums.size(), res = 0;

        for (int start=0; start<N; start++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> num2index;
            int distinct = 0, matched = 0;
            for (int end=start; end<N; end++) {
                if (!freq.contains(nums[end])) {
                    freq[nums[end]]++;
                    num2index[nums[end]] = distinct;
                    distinct++;
                    if (distinct == 1) {
                        matched = 1;
                        res++;
                    }
                } else {
                    freq[nums[end]]++;
                    int idx = num2index[nums[end]];
                    if (freq[nums[end]] == idx+1) {
                        matched++;
                    }
                    if (freq[nums[end]] > idx+1) {
                        break;
                    }
                    if (matched == distinct) {
                        res++;
                    }

                }
            }
        }

        return res;
    }
};