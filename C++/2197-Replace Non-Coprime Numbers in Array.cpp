// O(N*log(m)), m is the largest number in nums

// Although the time complexity of gcd(a, b) is O(log(min(a, b))),
// if the array starts with large numbers, the first few iterations
// can still take up to O(log(m)), where m is the maximum value in nums.

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> arr;

        for (int num:nums) {
            int tmp = num, x;
            while (!arr.empty() && (x = gcd(tmp, arr.back())) > 1) {  // assignment inside condition
                int prev = arr.back();
                arr.pop_back();
                tmp = tmp*(prev/x);
            }
            arr.push_back(tmp);
        }

        return arr;
    }
};