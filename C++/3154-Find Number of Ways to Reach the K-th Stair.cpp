using LL = long long;
class Solution {
public:
    int waysToReachStair(int k) {
        int diff = k-1;
        int res = 0;
        
        // the ways to reach without jumps
        if (diff == 0 || diff == -1) res++;

        // with jumps
        LL forward = 0;
        int j = 0, backward = 0;

        while (true) {
            forward += pow(2, j);
            backward = forward - diff;

            if (backward > j+2) break;
            else if (backward == 0) {
                res++;
            } else if (backward > 0) {
                // ( C(j+2, backward) )
                LL curr = 1;
                for (int i=1; i<=backward; i++) {
                    curr = curr*(j+2+1-i)/i;
                }
                res += int(curr);
            }
            // if backward < 0, j++ and continue
            j++;
        }
        return res;
    }
};