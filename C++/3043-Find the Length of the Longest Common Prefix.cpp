class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix;
        for (int x:arr1) {
            while (x > 0) {
                prefix.insert(x);
                x /= 10;
            }
        }
        
        int res = 0;
        for (int x:arr2) {
            while (x > 0) {
                if (prefix.contains(x)) {
                    res = max(res, (int)(log10(x)+1));
                    break;
                }
                x /= 10;
            }
        }        
        return res;
    }
};