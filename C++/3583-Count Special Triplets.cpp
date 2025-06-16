class Solution {
public:
    int kMod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt, pair;

        long long res = 0;

        long long zeroCnt = count(begin(nums), end(nums), 0);
        if (zeroCnt >= 3) {
            res = (res + zeroCnt*(zeroCnt-1)*(zeroCnt-2)/6)%kMod;
        }


        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                if (nums[i]%2 == 0) {
                    int half = nums[i]/2;
                    if (pair.contains(half)) {
                        res = (res + pair[half])%kMod;
                    }
                }
                if (cnt.contains(nums[i]*2)) {
                    pair[nums[i]] += cnt[nums[i]*2];
                }
                cnt[nums[i]]++;
            }
        }

        return res;
    }
};

// cleaned
class Solution {
public:
    int kMod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt, pair;

        long long res = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]%2 == 0) {
                int half = nums[i]/2;
                res = (res + pair[half])%kMod;
            }
            pair[nums[i]] = (pair[nums[i]] + cnt[nums[i]*2])%kMod;
            cnt[nums[i]]++;
        }

        return res;
    }
};