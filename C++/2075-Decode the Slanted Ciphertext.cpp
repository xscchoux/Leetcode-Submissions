class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int N = encodedText.size(), col = N/rows, row = rows;
        string res;

        int startR = 0;
        int startC = 0;
        while (startC < col) {
            int r = startR, c = startC;
            while (r < row && c < col) {
                res.push_back(encodedText[r*col+c]);
                r++;
                c++;
            }
            startC++;
        }        


        while (!res.empty() && isspace(res.back())) {
            res.pop_back();
        }

        return res;

    }
};