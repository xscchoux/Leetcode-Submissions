class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, score = 0;
        int left=0, right=tokens.size()-1;
        while (left <= right) {
            if (power < tokens[left] && score > 0) {
                score--;
                power += tokens[right];
                right--;
            } else if (power >= tokens[left]) {
                score++;
                power -= tokens[left];
                left++;
                res = max(res, score);
            } else {
                break;
            }
        }
        return res;
    }
};