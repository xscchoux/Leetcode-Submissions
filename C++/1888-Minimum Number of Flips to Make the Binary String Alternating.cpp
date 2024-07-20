// Counting
class Solution {
public:
    int minFlips(string s) {
        int evenOne = 0, oddOne = 0, evenZero = 0, oddZero = 0, N = s.size();
        for (int i=0; i<N; i++) {
            if (s[i] == '1') {
                if (i%2) oddOne++;
                else evenOne++;
            } else {
                if (i%2) oddZero++;
                else evenZero++; 
            }
        }

        int res = min(N-oddOne-evenZero, N-evenOne-oddZero);

        int curr = 0;
        while (curr < N) {
            if (s[curr] - '0' == 0) {
                if (N%2) {
                    evenZero--;
                    oddZero++;
                }
            } else {
                if (N%2) {
                    evenOne--;
                    oddOne++;
                }                    
            }
            swap(oddOne, evenOne);
            swap(oddZero, evenZero);         
            res = min(res, min(N-oddOne-evenZero, N-evenOne-oddZero));
            curr++;
        }

        return res;
    }
};



// sliding window
class Solution {
public:
    int minFlips(string s) {
        int N = s.size();
        int flip1 = 0, flip2 = 0, res = INT_MAX;
        
        for (int i=0; i<(2*N-1); i++) {
            if (i%2 != (s[i%N]=='0')?0:1) flip1++;
            if (i%2 == (s[i%N]=='0')?0:1) flip2++;
            if (i >= N) {
                int val = s[i-N]-'0';
                if ((i-N)%2 != val) flip1--;
                else flip2--;
            }
            if (i >= N-1) {
                res = min({res, flip1, flip2});
            }
        }
        return res;
    }
};



// Better sliding window
class Solution {
public:
    int minFlips(string s) {
        int N = s.size();
        int flip1 = 0, res = INT_MAX;
        
        for (int i=0; i<(2*N-1); i++) {
            if (i%2 != (s[i%N]=='0')?0:1) flip1++;
            if (i >= N) {
                int val = s[i-N]-'0';
                if ((i-N)%2 != val) flip1--;
            }
            if (i >= N-1) {
                res = min({res, flip1, N-flip1});
            }
        }
        return res;
    }
};