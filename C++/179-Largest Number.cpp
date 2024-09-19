class Solution {
public:
    static bool cmp(const int& A, const int& B) {
        string a = to_string(A), b = to_string(B);
        return a + b > b + a;  // Note that cmp(x, x) MUST BE false, don't write a+b >= b+a
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        if (nums[0] == 0) return "0";

        for (int num:nums) {
            res += to_string(num);
        }

        return res;
    }
};