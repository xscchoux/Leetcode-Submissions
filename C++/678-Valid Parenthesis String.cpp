class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;

        for (char c:s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                left--;
            } else {
                left++;
            }
            if (left < 0) return false;
        }


        for (char c:string(rbegin(s), rend(s))) {
            if (c == ')') {
                right++;
            } else if (c == '(') {
                right--;
            } else {
                right++;
            }
            if (right < 0) return false;
        }

        return true;
    }
};


// one pass
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, N = s.size();

        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                left--;
            } else {
                left++;
            }

            if (s[N-i-1] == ')') {
                right++;
            } else if (s[N-i-1] == '(') {
                right--;
            } else {
                right++;
            }           

            if (left < 0 || right < 0) return false;
        }

        return true;
    }
};