// TLE
using LL = long long;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        LL res = 0;
        int N = nums.size();
        multiset<int> mset;

        for (int i=0; i<N; i++) {
            if (!mset.empty()) {
                auto itRight = mset.upper_bound(upper-nums[i]); // position of nums[j]
                if (itRight != mset.begin()) {
                    auto itLeft = mset.lower_bound(lower-nums[i]);
                    if (itLeft != mset.end()) {
                        int dist1 = distance(mset.begin(), itRight) - 1;
                        int dist2 = distance(mset.begin(), itLeft); // This is O(n)
                        if (dist1 >= dist2) res += dist1-dist2 + 1;
                    }
                }   
            }
            mset.insert(nums[i]);
        }

        return res;
    }
};


// V
using LL = long long;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        LL res = 0;
        int N = nums.size();
        sort(begin(nums), end(nums));

        for (int i=0; i<N; i++) {
            auto right = upper_bound(nums.begin(), nums.begin()+i, upper-nums[i]);
            auto left = lower_bound(nums.begin(), nums.begin()+i, lower-nums[i]);
            res += (right-left);
        }

        return res;
    }
};


// Even better
using LL = long long;
class Solution {
public:
    int N;
    LL countSmallerEqual(vector<int>& nums, int target) {
        LL res = 0;
        int left = 0, right = N-1;
        while (left < right) {
            int val = nums[left] + nums[right];
            if (val <= target) {
                res += (right-left);
                left++;
            } else {
                right--;
            }
        }
        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        N = nums.size();
        sort(begin(nums), end(nums));

        return countSmallerEqual(nums, upper) - countSmallerEqual(nums, lower-1);
    }
};