// https://leetcode.com/problems/reach-a-number/solutions/990875/python-3-binary-search-math-explained/

class Solution {
public:
    bool isEqualOrGreater(int num, int target) {
        if ((long long)num*(num+1)/2 >= target) return true;
        return false;
    }
    int reachNumber(int target) {
        target = abs(target);
        int left = 1, right = target/2+1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isEqualOrGreater(mid, target)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int step;
        
        if (isEqualOrGreater(left, target)) {
            step = left;
        } else {
            step = right;
        }

        // case1: diff is even -> step does not change, flip previous steps
        // case2: diff is odd, step is even -> need one more step
        // case3: diff is odd, step is odd  -> need two more steps

        int diff = target - (step*(step+1)/2);
        if (diff%2) {
            step += (step%2) + 1;
        }

        return step;
    }
};