class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int num:nums) cnt[num]++;
        int arrayCnt = 0;
        for (auto &[k, v]:cnt) {
            arrayCnt = max(arrayCnt, v);
        }

        int N = nums.size();
        return N >= arrayCnt*k;
    }
};