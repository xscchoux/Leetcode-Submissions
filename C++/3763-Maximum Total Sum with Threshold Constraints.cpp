class Solution {
public:
    long long maxSum(vector<int>& nums, vector<int>& threshold) {
        vector<pair<int, int>> arr;
        for (int i=0; i<nums.size(); i++) {
            arr.push_back({threshold[i], nums[i]});
        }

        sort(arr.begin(), arr.end());

        int step = 1;
        long long res = 0;
        for (int i=0; i<arr.size(); i++) {
            if (step < arr[i].first) break;
            res += arr[i].second;
            step++;
        }

        return res;
    }
};