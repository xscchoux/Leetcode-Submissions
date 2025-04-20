class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int N = instructions.size();
        vector<bool> visited(N, false); 
        int currPos = 0;
        long long score = 0;

        while (currPos >= 0 && currPos < N && !visited[currPos]) {
            visited[currPos] = true;
            if (instructions[currPos] == "jump") {
                currPos += values[currPos];
            } else {
                score += values[currPos];
                currPos++;
            }
        }

        return score;
    }
};