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
    int minStartingIndex(string s, string pattern) {
        string str = pattern + '#' + s;
        string reversedS = string(s.rbegin(), s.rend());
        string reversedPattern = string(pattern.rbegin(), pattern.rend());
        string reversed_str = reversedPattern + '#' + reversedS;
        
        vector<int> z1 = z_array(str);
        vector<int> z2 = z_array(reversed_str);
        int Psz = pattern.size();
        z1 = vector<int>(z1.begin()+Psz+1, z1.end());
        z2 = vector<int>(z2.begin()+Psz+1, z2.end());
        reverse(begin(z2), end(z2));

        int N = s.size();
        for (int i=0; i<N; i++) {
            if (i+Psz-1 >= N) break;
            if ( Psz - z1[i] - z2[i+Psz-1] <= 1) { // This is brilliant
                return i;
            }
        }

        return -1;
    }
};