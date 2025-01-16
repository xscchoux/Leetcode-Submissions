// first AC, lengthy
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0;
        while (num2 > 0) {
            num2 = (num2 & (num2-1));
            setBits++;
        }
        vector<int> bitArr;
        int tmp1 = num1;
        while (tmp1 > 0) {
            if (tmp1&1) {
                bitArr.push_back(1);
            } else {
                bitArr.push_back(0);
            }
            tmp1 /= 2;
        }

        vector<bool> flipped(bitArr.size(), false);
        for (int i=bitArr.size()-1; i>=0; i--) {
            if (bitArr[i] == 1) {
                bitArr[i] = 0;
                setBits--;
                flipped[i] = true;
                if (setBits == 0) break;
            }
        }

        if (setBits > 0) {
            for (int i=0; i<bitArr.size(); i++) {
                if (!flipped[i] && setBits > 0) {
                    bitArr[i] = 1;
                    setBits--;
                    if (setBits == 0) {
                        break;
                    }
                }
            }
        }

        int res = 0;
        for (int i=bitArr.size()-1; i>=0; i--) {
            res = res*2;
            res += bitArr[i];
        }

        int N = bitArr.size();
        while (setBits > 0) {
            res += (1<<N);
            N++;
            setBits--;
        }

        return res^num1;
    }
};


// clever one
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsCnt1 = __builtin_popcount(num1), setBitsCnt2 = __builtin_popcount(num2);  // target set bit count
        int pos = 0, res = num1;

        // case1: setBitsCnt1 < target set bits
        while (setBitsCnt1 < setBitsCnt2) {
            if (!((1<<pos)&res)) {  // if there if a 0, flip to 1
                res |= (1<<pos);
                setBitsCnt1++;
            }
            pos++;
        }

        // case2: setBitsCnt1 > target set bits
        while (setBitsCnt1 > setBitsCnt2) {
            if (((1<<pos)&res)) {  // if there if a 1, flip to 0
                res &= ~(1<<pos);
                setBitsCnt1--;
            }
            pos++;
        }

        return res;
    }
};