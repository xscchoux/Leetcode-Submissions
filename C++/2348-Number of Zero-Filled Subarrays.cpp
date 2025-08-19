class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                res += cnt*(cnt+1)/2;  // need implicit promotion to make 2 -> (long long)2
                cnt = 0;
            }
        }

        res += cnt*(cnt+1)/2;

        return res;
    }
};


// A little faster
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                res += (long long)cnt*(cnt+1)/2;
                cnt = 0;
            }
        }

        res += (long long)cnt*(cnt+1)/2;

        return res;
    }
};

// This is faster because in C++, the rule is:

// If one operand is long long and the other is int, the int gets promoted to long long before the operation.

// So (long long)cnt * (cnt + 1)
// is actually equivalent to:

// (long long)cnt * (long long)(cnt + 1)


// Then divide by 2:

// 2 is an int, but since the left side is already long long, 2 will be promoted to long long.

// So the whole expression is effectively:

// (long long)cnt * (long long)(cnt + 1) / (long long)2

// That means: once you introduce a (long long) in the expression, the entire arithmetic will be carried out in long long.


// In short: (long long) doesn’t just “change cnt”—it effectively lifts the whole expression to long long arithmetic.