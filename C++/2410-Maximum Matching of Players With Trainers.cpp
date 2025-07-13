class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int res = 0, j = 0;

        for (int i=0; i<players.size() && j < trainers.size(); i++) {
            while (j < trainers.size() && players[i] > trainers[j]) {
                j++;
            }

            if (j < trainers.size()) {
                res++;
                j++;
            } else {
                break;
            }
        }

        return res;
    }
};
