class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        vector<int> prev;
        prev.push_back(0);

        for (int num:nums) {
            vector<int> temp;
            for (int preVal:prev) {
                res += preVal^num;
                temp.push_back(preVal^num);
            }
            for (int t:temp) {
                prev.push_back(t);
            }
        }

        return res;
    }
};


// O(N)
// Each '1' has 2^(N-1) combinations:
// If we pick other even number of '1', use this '1'
// If we pick other odd number of '1', don't use this '1'

// Detail: https://leetcode.cn/problems/sum-of-all-subset-xor-totals/solutions/3614974/on-shu-xue-zuo-fa-pythonjavaccgojsrust-b-9txy/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int tot = 0;
        for (int num:nums) tot |= num;

        return tot << (nums.size()-1);

    }
};

// Use ranges::fold_left()
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return ranges::fold_left(nums, 0, [](int a, int b) { return a|b; }) << (nums.size()-1);
    }
};

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return ranges::fold_left(nums, 0, bit_or{}) << (nums.size()-1);
    }
};