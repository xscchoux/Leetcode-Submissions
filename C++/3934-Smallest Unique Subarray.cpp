class Solution {
public:
    int N;
    bool isOK(vector<int>& nums, int length) {
        // gcd(base, kMod) = 1, base doesn't necessarily need to be a prime, kMod should be
        long long base = 200003;
        long long kMod = 1e9+7;
        long long hashVal = 0, power = 1;

        unordered_map<long long, int> cnt;
        
        for (int i=0; i<length; i++) {
            hashVal = (hashVal*base + nums[i])%kMod;
            power = (power*base)%kMod;
        }
        cnt[hashVal]++;

        for (int i=length; i<N; i++) {
            hashVal = (hashVal*base + nums[i] - nums[i-length]*power%kMod)%kMod;
            if (hashVal < 0) hashVal = (hashVal + kMod)%kMod;
            cnt[hashVal]++;
        }

        for (auto &[k, v]:cnt) {
            if (v == 1) return true;
        }

        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        this->N = nums.size();
        int left = 1, right = N;
        
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, left)){
            return left;
        }

        return right;
    }
};



// Double rolling hash
class Solution {
public:
    int N;
    bool isOK(vector<int>& nums, int length) {
        // gcd(base, kMod) = 1, base doesn't necessarily need to be a prime, kMod should be
        long long base1 = 200003, base2 = 200023;
        long long kMod1 = 1e9+7, kMod2 = 1e9+9;
        
        long long hashVal1 = 0, hashVal2 = 0, power1 = 1, power2 = 1;

        map<pair<long, long>, int> cnt;
        
        for (int i=0; i<length; i++) {
            hashVal1 = (hashVal1*base1 + nums[i])%kMod1;
            power1 = (power1*base1)%kMod1;

            hashVal2 = (hashVal2*base2 + nums[i])%kMod2;
            power2 = (power2*base2)%kMod2;
        }
        cnt[{hashVal1, hashVal2}]++;

        for (int i=length; i<N; i++) {
            hashVal1 = (hashVal1*base1 + nums[i] - nums[i-length]*power1%kMod1)%kMod1;
            if (hashVal1 < 0) hashVal1 = (hashVal1 + kMod1)%kMod1;

            hashVal2 = (hashVal2*base2 + nums[i] - nums[i-length]*power2%kMod2)%kMod2;
            if (hashVal2 < 0) hashVal2 = (hashVal2 + kMod2)%kMod2;
            cnt[{hashVal1, hashVal2}]++;
        }

        for (auto &[k, v]:cnt) {
            if (v == 1) return true;
        }

        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        this->N = nums.size();
        int left = 1, right = N;
        
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, left)){
            return left;
        }

        return right;
    }
};