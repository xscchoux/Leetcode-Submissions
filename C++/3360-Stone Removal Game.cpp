class Solution {
public:
    bool canAliceWin(int n) {
        bool isAlice = true;
        int curr = 10;
        while (n >= 0) {
            if (n-curr < 0) {
                return !isAlice;
            }
            n -= curr;
            curr--;
            isAlice = !isAlice;
        }

        return true;
    }
};