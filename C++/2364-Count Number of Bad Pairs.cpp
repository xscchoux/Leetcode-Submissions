class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int N = nums.size();
        long long res = 0;
        
        for (int i=0; i<N; i++) {
            res += i - cnt[nums[i]-i];
            cnt[nums[i]-i]++;
        }

        return res;
    }
};