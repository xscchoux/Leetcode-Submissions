class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        for (int i=1; i<currentState.size(); i++) {
            if(currentState[i] == '+' && currentState[i-1] == '+') {
                string toPush = currentState;
                toPush[i] = '-';
                toPush[i-1] = '-';
                res.push_back(toPush);
            }
        }
        return res;
    }
};