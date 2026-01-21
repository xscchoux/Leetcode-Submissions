class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        unordered_map<char, int> cnt;
        // count frequency of each char
        for (char c:s) {
            cnt[c]++;
        }

        // delete previous char when ( current char < previous char && cnt[previous char] >= 2)
        stack<int> stk;
        for (int i=0; i<s.size(); i++) {
            while (!stk.empty() && s[i] < s[stk.top()] && cnt[s[stk.top()]] >= 2) {
                cnt[s[stk.top()]]--;
                stk.pop();
            }
            stk.push(i);
        }

        string res = "";
        while (!stk.empty()) {
            res += s[stk.top()];
            stk.pop();
        }

        reverse(begin(res), end(res));

        // handle the case when cnt[last char] >= 2
        while (!res.empty() && cnt[res.back()] >= 2) {
            cnt[res.back()]--;
            res.pop_back();
        }

        return res;
    }
};