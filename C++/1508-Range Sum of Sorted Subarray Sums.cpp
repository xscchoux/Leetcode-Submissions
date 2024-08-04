// brute-force
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        int N = nums.size(), kMod = 1e9+7;
        for (int i=0; i<N; i++) {
            int curr = 0;
            for (int j=i; j<N; j++) {
                curr += nums[j];
                arr.push_back(curr);
            }
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i=left-1; i<=right-1; i++) {
            res = (res + arr[i])%kMod;
        }

        return res;
    }
};



// Hard binary search solution
using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    LL binarySearch(vector<int>& nums, int minCount, LL mn, LL mx) {
        int l = mn, r = mx;
        while (l+1 < r) {
            int mid = l + (r-l)/2;
            if (countSmaller(nums, mid).first >= minCount) {
                r = mid;
            } else {
                l = mid;
            }
        }

        auto [count1, sum1] = countSmaller(nums, l);
        if (count1 >= minCount) {
            return sum1 - l*(count1-minCount);
        }

        auto [count2, sum2] = countSmaller(nums, r);
        return sum2 - r*(count2-minCount);

    }
    pair<int, LL> countSmaller(vector<int>& nums, LL limit) {
        int left = 0, N = nums.size();
        int curr = 0, count = 0;
        LL windowSum = 0, totSum = 0;
        for (int i=0; i<N; i++) {
            curr += nums[i];
            windowSum += nums[i]*(i-left+1);
            while (curr > limit) {
                windowSum -= curr;
                curr -= nums[left++];
            }
            count += (i-left+1);
            totSum += windowSum;
        }
        return {count, totSum};
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = accumulate(nums.begin(), nums.end(), 0);

        LL rightSum = binarySearch(nums, right, mn, mx);
        LL leftSum = binarySearch(nums, left-1, mn, mx);

        return (rightSum-leftSum)%kMod;
    }
};