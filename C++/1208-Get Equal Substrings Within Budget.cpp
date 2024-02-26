class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> arr;
        for (int i=0; i<s.size(); i++) arr.push_back(abs(s[i]-t[i]));

        int left = 0, curr = 0, i;
        for (i=0; i<s.size(); i++) {
            curr += arr[i];
            if (curr > maxCost) {
                curr -= arr[left++];
            }
        }
        return i-left;
    }
};