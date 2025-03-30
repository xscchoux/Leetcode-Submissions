class Solution {
public:
    bool isPalindrome(string &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int Ns= s.size(), Nt = t.size(), res = 1;
        for (int i=0; i<Ns; i++) {
            for (int j=i; j<=Ns; j++) {
                string sub1 = s.substr(i, j-i);
                for (int k=0; k<Nt; k++) {
                    for (int l=k; l<=Nt; l++) {
                        string sub2 = t.substr(k, l-k);
                        string curr = sub1+sub2;
                        if (isPalindrome(curr)) res = max(res, (int)curr.size());
                    }
                }
            }
        }

        return res;
    }
};