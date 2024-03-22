using LL = long long;
class Solution {
public:
    long long countSubstrings(string s, char c) {
        vector<int> arr;
        LL res = 0LL;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == c) {
                arr.push_back(i);
            }
        }
        
        int N = arr.size();
        for (int i=0; i<N; i++) {
            res += N-i;
        }
        
        return res;
    }
};