class Solution {
public:
    string convert(int num) {
        string s;
        while (num > 0) {
            s += num%2+'0';
            num = num/2;
        }
        reverse(begin(s), end(s));
        return s;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num:nums) {
            arr.push_back(convert(num));
        }
        sort(begin(arr), end(arr), [](string &a, string &b) {
            return a+b > b+a;
        });

        string res;
        for (string x:arr) {
            res += x;
        }

        return stoi(res, nullptr, 2);
    }
};