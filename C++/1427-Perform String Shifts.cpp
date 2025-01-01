class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int move = 0;
        for (auto &s:shift) {
            if (s[0] == 0) move += s[1];
            else move -= s[1];
        }
        int N = s.size();
        move = (move%N + N)%N;

        return s.substr(move) + s.substr(0, move);

    }
};