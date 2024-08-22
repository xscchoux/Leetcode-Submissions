class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int p = 0;
        while (num > 0) {
            int curr = (num%2)^1;
            res += curr*pow(2, p++);
            num /= 2;
        }
        return res;
    }
};


// count digits
class Solution {
public:
    int findComplement(int num) {
        int digits = log2(num) + 1;

        num = num^((int)(pow(2, digits)-1));

        return num;
    }
};