class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Four cases: all even, all odd, odd even ..., even odd ...
        vector<int> cnt(2, 0);
        vector<int> end(2, 0);  // (end with even, end with odd)

        for (int num:nums) {
            cnt[num%2]++;
            end[num%2] = end[1-num%2] + 1;
        }

        return max({cnt[0], cnt[1], end[0], end[1]});
    }
};