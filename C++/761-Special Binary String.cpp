// https://leetcode.cn/problems/special-binary-string/solutions/3905099/ben-zhi-shi-he-fa-gua-hao-zi-fu-chuan-di-x6ci/
// O(N^2)
// In worst case, T(n) = T(n-2) + O(n) ≈ O(n) + O(n-2) + O(n-4) + ... + O(2) ≈ O(n²) 
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s;
        }
        vector<string> arr;
        int cnt = 0, N = s.size(), left = 0;

        for (int i=0; i<N; i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    arr.push_back('1' + makeLargestSpecial( s.substr(left+1, i-1-(left+1)+1) ) + '0');
                    left = i+1;
                }
            }
        }

        sort(begin(arr), end(arr), greater<>());

        string res = "";
        for (auto &block:arr) {
            res += block;
        }
        return res;

    }
};