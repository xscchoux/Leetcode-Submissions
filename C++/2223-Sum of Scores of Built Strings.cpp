using LL = long long;
class Solution {
public:
    vector<int> z_array(string& s) {
        int N = s.size();
        vector<int> Z(N, 0);
        int l = 0, r = 0;
        for (int i=1; i<N; i++) {
            if (i>r) {
                l = r = i;
                while (r<N && s[r] == s[r-l]) {
                    r++;
                }
                Z[i] = r-l;
                r--;
            } else {
                int k = i-l;
                if (i + Z[k] <= r) {
                    Z[i] = Z[k];
                } else {
                    l = i;
                    while (r<N && s[r] == s[r-l]) {
                        r++;
                    }
                    Z[i] = r-l;
                    r--;                    
                }
            }
        }
        return Z;
    }
    long long sumScores(string s) {
        vector<int> arr = z_array(s);
        LL res = accumulate(begin(arr), end(arr), 0LL);
        return res + s.size();
    }
};
