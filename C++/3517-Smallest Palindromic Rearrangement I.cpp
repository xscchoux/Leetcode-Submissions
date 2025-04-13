// First AC
class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> hmap;
        for (char c:s) {
            hmap[c]++;
        }
        
        string half;
        char oddChar;
        int oddCount = 0;

        for (auto &[k, v]:hmap) {
            if (v%2 == 0) half += string(v/2, k), cout << half << endl;
            else {
                oddChar = k;
                oddCount = v;
            }
        }

        if (oddCount) {
            return half + string(oddCount, oddChar) + string(rbegin(half), rend(half));
        } else {
            return half + string(rbegin(half), rend(half));
        }
    }
};


// much faster
class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char c:s) {
            cnt[c-'a']++;
        }
        
        int left = 0, right = s.size()-1;
        
        for (int k=0; k<26; k++) {
            if (cnt[k] >= 2) {
                while (cnt[k] >= 2) {
                    cnt[k] -= 2;
                    s[left++] = s[right--] = (k +'a');
                }
            }
            if (cnt[k]) {
                s[s.size()/2] = k+'a';
            }
        }

        return s;
    }
};