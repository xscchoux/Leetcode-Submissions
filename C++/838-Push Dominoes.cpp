class Solution {
public:
    string pushDominoes(string dominoes) {
        string res = "";
        int N = dominoes.size();
        vector<int> totForce(N, 0);

        int force = 0;  // left force is positive
        for (int i=N-1; i>=0; i--) {
            if (dominoes[i] == 'R') {
                force = 0;
            }
            else if (dominoes[i] == 'L') {
                force = N;
            } else if (dominoes[i] == '.' && force > 0){
                force--;
            }
            totForce[i] += force;
        }

        force = 0;
        for (int i=0; i<N; i++) {
            if (dominoes[i] == 'L') {
                force = 0;
            }
            else if (dominoes[i] == 'R') {
                force = -N;
            } else if (dominoes[i] == '.' && force < 0){
                force++;
            }
            totForce[i] += force;

            // fill res
            if (totForce[i] > 0) res += 'L';
            else if (totForce[i] == 0) res += '.';
            else res += 'R';
        }

        return res;
    }
};