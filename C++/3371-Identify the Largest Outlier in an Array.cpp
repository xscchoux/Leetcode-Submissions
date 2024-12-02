class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num:nums) cnt[num]++;
        int tot = accumulate(begin(nums), end(nums), 0);
        int res = INT_MIN;
        
        for (int num:nums) {
            int tmp = tot-num;
            cnt[num]--;
            if (tmp%2 == 0) {
                int half = tmp/2;
                if (cnt[half] > 0) res = max(res, num);
            }
            cnt[num]++;
        }

        return res;
    }
};