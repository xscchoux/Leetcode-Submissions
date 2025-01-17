using LL = long long;
class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        multiset<int> lower, upper;
        LL lowerSum = 0, upperSum = 0, res = LLONG_MAX;
        int N = nums.size();

        for (int i=0; i<k-1; i++) {
            lower.insert(nums[i]);
            lowerSum += nums[i];
        }

        bool oddLen = k%2?true:false;

        for (int i=k-1; i<N; i++) {
            lower.insert(nums[i]);
            lowerSum += nums[i];

            // size balance
            while (lower.size() > upper.size()) {
                int lowerRight = *prev(lower.end());
                upper.insert(lowerRight);
                lower.erase(prev(lower.end()));
                lowerSum -= lowerRight;
                upperSum += lowerRight;
            }

            // make sure the largest in lower is smaller or equal to the smallest in upper
            while (!upper.empty() && *prev(lower.end()) > *upper.begin()) {
                int lowerRight = *prev(lower.end());
                int upperLeft = *upper.begin();
                lower.erase(prev(lower.end()));
                upper.erase(upper.begin());
                lower.insert(upperLeft);
                upper.insert(lowerRight);

                lowerSum -= (lowerRight - upperLeft);
                upperSum += (lowerRight - upperLeft);
            }

            // get median
            LL operations;
            if (oddLen) {
                operations = upperSum - lowerSum - *upper.begin();
            } else {
                operations = upperSum - lowerSum;
            }
            res = min(res, operations);

            // erase the leftmost element
            int leftMost = nums[i-(k-1)];
            if (upper.find(leftMost) != upper.end()) {
                upper.erase(upper.find(leftMost));
                upperSum -= leftMost;
            } else {
                lower.erase(lower.find(leftMost));
                lowerSum -= leftMost;
            }
        }

        return res;
    }
};