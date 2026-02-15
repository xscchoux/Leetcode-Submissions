class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num:nums) {
            cnt[num]++;
        }

        unordered_map<int, int> freqCnt;
        for (auto it:cnt) {
            freqCnt[it.second]++;
        }

        for (int num:nums) {
            if (freqCnt[cnt[num]] == 1) {
                return num;
            }
        }

        return -1;
    }
};