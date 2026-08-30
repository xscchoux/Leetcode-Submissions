class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, vector<int>> primeFactor;

        for (int num:nums) {
            if (primeFactor.contains(num)) continue;
            // calculate prime factors
            int tmp = num;
            for (int i=2; i*i <= num; i++) {
                if (tmp%i == 0) {
                    primeFactor[num].push_back(i);
                    while (tmp%i == 0) {
                        tmp = tmp/i;
                    }
                }
            }

            if (tmp > 1) {
                primeFactor[num].push_back(tmp);
            }
        }

        unordered_map<int, int> cnt;
        int res = 0, left = 0;
        for (int i=0; i<N; i++) {
            
            for (int factor:primeFactor[nums[i]]) {
                cnt[factor]++;
            }

            while (cnt.size() > k) {
                
                for (int factor:primeFactor[nums[left]]) {
                    cnt[factor]--;
                    if (cnt[factor] == 0) {
                        cnt.erase(factor);
                    }
                }

                left++;
            }

            res = max(res, i-left+1);
        }

        return res;  
    }
};