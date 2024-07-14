class Solution {
public:
    string getSmallestString(string s) {
        for (int i=1; i<s.size(); i++) {
            int num = s[i] - '0';
            int pre = s[i-1] - '0';
            if (num%2 == pre%2 && num < pre) {
                swap(s[i], s[i-1]);
                break;
            }
        }

        return s;
    }
};