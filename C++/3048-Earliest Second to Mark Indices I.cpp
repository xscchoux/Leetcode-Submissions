// https://leetcode.com/problems/earliest-second-to-mark-indices-i/discuss/4778544/Python-or-Binary-Search-(m-*-log(m))-or-Iterate-from-Back
using LL = long long;
class Solution {
public:
    bool isOK(int limit, vector<int>& nums, vector<int>& changeIndices) {
        unordered_set<int> seen;
        LL ops = 0;
        for (int ind=limit; ind>=1; ind--) {
            int numIdx = changeIndices[ind-1];
            if (!seen.count(numIdx)) {
                seen.insert(numIdx);
                ops += nums[numIdx-1];
            } else if (ops > 0) {
                ops--;
            }
        }
        
        if (seen.size() != nums.size()) return false;
        return ops == 0;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int left = 1, right = changeIndices.size();
        
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(mid, nums, changeIndices)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        if (isOK(left, nums, changeIndices)) {
            return left;
        } else if (isOK(right, nums, changeIndices)) {
            return right;
        } else {
            return -1;
        }
    }
};