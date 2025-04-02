// O(N^2), z algorithm + calculating palindrome length 
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
    vector<int> palindromeLengthS(string &s) {
        int N = s.size();
        vector<int> length(N, 1);  // length of longest palindrome that starts with ith index
        vector<vector<bool>> check(N, vector<bool>(N, false));
        for (int i=0; i<N; i++) check[i][i] = true;

        for (int len = 2; len <= N; len++) {
            for (int start=0; start<N; start++) {
                if (start+len-1 >= N) break;
                int end = start+len-1;
                if (s[start] == s[end] && (start + 1 == end || (start+1 <= end-1 && check[start+1][end-1])) ) {
                    check[start][end] = true;
                    length[start] = end-start+1;
                }
            }
        }

        return length;
    }
    vector<int> palindromeLengthT(string &s) {
        int N = s.size();
        vector<int> length(N, 1);  // length of longest palindrome that starts with ith index
        vector<vector<bool>> check(N, vector<bool>(N, false));
        for (int i=0; i<N; i++) check[i][i] = true;

        for (int len = 2; len <= N; len++) {
            for (int start=0; start<N; start++) {
                if (start+len-1 >= N) break;
                int end = start+len-1;
                if (s[start] == s[end] && (start + 1 == end || (start+1 <= end-1 && check[start+1][end-1])) ) {
                    check[start][end] = true;
                    length[end] = end-start+1;  // only this line is different from palindromeLengthT
                }
            }
        }

        return length;
    }

    int longestPalindrome(string s, string t) {
        // case 1: A palindrome exists only in s or only in t
        // case 2: A prefix from s and a suffix from t form a palindrome
        // case 3: A prefix from s, a palindrome within s, and a suffix from t form a palindrome
        // case 4: A prefix from s, a palindrome within t, and a suffix from t form a palindrome
        // I intentionally implement cases 2, 3, and 4 separately here 

        int N = s.size(), res;
        // case 1
        vector<int> lenS = palindromeLengthS(s);
        vector<int> lenT = palindromeLengthT(t);         
        res = max(*max_element(begin(lenS), end(lenS)), *max_element(begin(lenT), end(lenT)));

        // case 2
        string reversed_t = t;
        reverse(reversed_t.begin(), reversed_t.end());

        for (int i=0; i<N; i++) {
            string curr = s.substr(i) + '#' + reversed_t;
            vector<int> zArr = z_array(curr);
            for (int j = N-i+1; j<curr.size(); j++) {
                // case 2
                res = max(res, zArr[j]*2);
                
                // case 3
                if (zArr[j] > 0 && i + zArr[j] < N) res = max(res, zArr[j]*2 + lenS[i+zArr[j]]);
                
                // case 4
                int tIdx = t.size() - 1 - (j - (N-i+1));
                if (zArr[j] > 0 &&  tIdx - zArr[j] >= 0) res = max(res, zArr[j]*2 + lenT[tIdx - zArr[j]]);
            }
        }

        return res;
    }
};