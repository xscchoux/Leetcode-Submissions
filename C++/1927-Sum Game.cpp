class Solution {
public:
    bool sumGame(string num) {
        int N = num.size();
        int leftCnt = 0, rightCnt = 0, leftSum = 0, rightSum = 0;

        for (int i=0; i<N/2; i++) {
            if (num[i] == '?') {
                leftCnt++;
            } else {
                leftSum += num[i]-'0';
            }
        }

        for (int i=N/2; i<N; i++) {
            if (num[i] == '?') {
                rightCnt++;
            } else {
                rightSum += num[i]-'0';
            }
        }

        if (rightCnt == leftCnt) {
            return leftSum != rightSum;
        }

        int diffCnt = rightCnt-leftCnt;

        // When diffCnt is odd, since Alice goes first, the last question mark must be filled by Alice, and make the sums unequal
        if (diffCnt%2 != 0) return true;


        // If Alice picks x, Bob picks 9-x. 
        return leftSum-rightSum != (diffCnt/2)*9;
    }
};