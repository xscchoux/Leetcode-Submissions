class Solution {
public:
    int maxDiff(int num) {
        string stringNum = to_string(num);
        string stringX = stringNum, stringY = stringNum;
        int x=0, y=0, N=stringNum.size();
        
        while (x < N && stringNum[x]=='9') x++;
        if (x < N) {
            for (int i=0; i<N; i++) {
                if (stringX[i] == stringNum[x]) stringX[i] = '9';
            }
        }

        while (y < N && stringNum[y]=='0'||stringNum[y]=='1') y++;
        if (y < N) {
            for (int i=0; i<N; i++) {
                if (stringY[i] == stringNum[y]) {
                    if (y==0) {
                        stringY[i] = '1';
                    } else {
                        stringY[i] = '0';
                    }
                }
            }
        }

        return stoi(stringX) - stoi(stringY);
    }
}; 