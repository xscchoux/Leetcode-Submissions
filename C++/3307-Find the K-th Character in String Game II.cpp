// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/editorial/?envType=daily-question&envId=2025-07-04
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int opCount = 0;  // sum up all opertions if opertions[i] == 1 

        while (k > 1) {
            int t = __lg(k);  // ⌊log₂(k)⌋
            if (k == ((long long)1<<t)) {
                t--;
            }
            k -= ((long long)1<<t);
            opCount += operations[t];
        }

        return 'a' + opCount%26;
    }
};