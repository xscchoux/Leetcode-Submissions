class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        // O(nlogn)
        int steps = 0, N = rooks.size();
        sort(rooks.begin(), rooks.end());

        for (int i=0; i<N; i++) {
            steps += abs(i-rooks[i][0]);
            rooks[i][0] = i;
        }

        sort(rooks.begin(), rooks.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        for (int i=0; i<N; i++) {
            steps += abs(i-rooks[i][1]);
        }        

        return steps;


        // clever but hard O(n) solution
        int N = rooks.size();
        vector<int> row(N, 0), col(N, 0);

        for (vector<int> rook:rooks) {
            row[rook[0]]++;
            col[rook[1]]++;
        }

        int rowBalance = 0, colBalance = 0;
        int move = 0;
        for (int i=0; i<N; i++) {
            rowBalance += row[i]-1; // can be positive or negative, indicating the current shortage or surplus of rooks from rows 0 to i
            colBalance += col[i]-1;
            move += abs(rowBalance) + abs(colBalance); // total moves needed to resolve unbalanced rows and columns so far
        }

        return move;
    }
};