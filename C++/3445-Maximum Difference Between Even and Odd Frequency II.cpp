class Solution {
public:
    int getState(int cntA, int cntB) {
        return (cntA%2)*2 + cntB%2;
    }
    int maxDifference(string s, int k) {
        int N = s.size(), res = INT_MIN;

        for (char a='0'; a<='4'; a++) {
            for (char b='0'; b<='4'; b++) {
                int cntA = 0, cntB = 0, prevA = 0, prevB = 0, left = 0; // prevA and prevB updates with the left pointer
                vector<int> stateDP(4, INT_MAX); // four states: 10, 01, 00, 11, and their corresponding value of cntA-cntB
                for (int i=0; i<N; i++) {
                    cntA += (s[i] == a);
                    cntB += (s[i] == b);
                    while (i-left+1 >= k && cntB - prevB >= 2) {
                        int leftState = getState(prevA, prevB);  // the while loop mainly updates stateDP, prevA, and prevB
                        stateDP[leftState] = min(stateDP[leftState], prevA-prevB);
                        prevA += (s[left] == a);
                        prevB += (s[left] == b);
                        left++;
                    }

                    int currState = getState(cntA, cntB);
                    if (stateDP[currState^0b10] != INT_MAX) {
                        res = max(res, cntA-cntB-stateDP[currState^0b10]); // we can just use currState^2 here
                    }
                }
            }       
        }
        return res;
    }
};