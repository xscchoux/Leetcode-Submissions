class Solution {
public:
    int numberOfSubstrings(string s) {
        // https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/solutions/5546675/o-n-sqrt-n/
        int N = s.size(), res = 0;
        for (int z=0; z+z*z<=N; z++) {
            int numZero = 0, numOne = 0, left = 0, lastStart = 0, old_res = res;
            for (int i=0; i<N; i++) {
                if (s[i] == '1') numOne++;
                else numZero++;
                while (numZero > z) {
                    if (s[left++] == '0') numZero--;
                    else numOne--;
                }
                if (numZero == z && numOne>0 && numOne >= z*z) {
                    lastStart = max(lastStart, left);
                    for (;lastStart<i && s[lastStart] == '1'; lastStart++);
                    res += 1 + min(lastStart-left, numOne-z*z);
                }
            }
            if (old_res == res) break;
        }
        return res;
    }
};



// Redo, still a tough one
// https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/3234.Count-the-Number-of-Substrings-With-Dominant-Ones/3234.Count-the-Number-of-Substrings-With-Dominant-Ones.cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.size(), sqrtN = sqrt(N), res = 0;

        vector<int> rightOnes(N, 0);  // consecutive ones starting from i+1
        int curr = 0;
        for (int i=N-1; i>=0; i--) {
            rightOnes[i] = curr;
            if (s[i] == '1') {
                curr++;
            } else {
                curr = 0;
            }
        }

        for (int m=1; m<=sqrtN; m++) {   // m: number of zeros in the window
            int zeroCnt = 0, rightIdx = 0;
            for (int leftIdx=0; leftIdx < N; leftIdx++) {
                while (rightIdx < N && zeroCnt < m) {
                    zeroCnt += (s[rightIdx] == '0');
                    rightIdx++;
                }
                if (zeroCnt < m) break;

                // count substrings starting with s[leftIdx] and also having m zeros and dominant ones
                int oneCnt = rightIdx-leftIdx - m;
                if (m*m <= oneCnt + rightOnes[rightIdx-1]) {
                    int extraOnes = rightOnes[rightIdx-1] - max(0, m*m-oneCnt);
                    res += extraOnes+1;
                }
                zeroCnt -= (s[leftIdx] == '0');
            }
        }

        // substrings that only contain 1
        for (int i=0, cnt=0; i<N; i++) {
            if (s[i] == '1') {
                cnt++;
                res += cnt;
            } else {
                cnt = 0;
            }
        }

        return res;
    }
};