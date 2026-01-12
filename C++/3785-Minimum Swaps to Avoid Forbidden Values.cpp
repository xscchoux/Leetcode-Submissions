class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int N = nums.size();
        unordered_map<int, int> freq;

        int badPairs = 0;
        unordered_map<int, int> badPairMap;
        for (int i=0; i<N; i++) {
            freq[nums[i]]++;
            freq[forbidden[i]]++;
            if (nums[i] == forbidden[i]) {
                badPairs++;
                badPairMap[nums[i]]++;
            }
        }

        for (auto [k, v]:freq) {
            if (v > N) return -1;
        }

        int maxPairCnt = 0;
        for (auto [k, v]:badPairMap) {
            maxPairCnt = max(maxPairCnt, v);
        }
        
        return max((badPairs+1)/2, maxPairCnt);
    }
};