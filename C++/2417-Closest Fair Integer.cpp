class Solution {
public:
    // https://leetcode.com/problems/closest-fair-integer/discuss/2643345/Python-Readable-Solution-with-explanation.
    int balanceInt(string stringN, int idx) {
        int oddNum = 0;
        int N = stringN.size();
        for (int i=0; i<=idx; i++) {
            if ((stringN[i]-'0')%2 == 1) oddNum++; 
        }
        int evenNum = idx+1-oddNum;
        if (2*oddNum > N || 2*evenNum > N) return -1;
        int diff = oddNum-evenNum;
        int restNum = N-(idx+1);
        int evenCount = (restNum+diff)/2, oddCount = (restNum-diff)/2;

        return stoi(stringN.substr(0, idx+1) + string(evenCount, '0') + string(oddCount, '1'));
    }
    
    int closestFair(int n) {
        string stringN = to_string(n);
        int length = stringN.size();
        if (length%2) return stoi('1' + string(length/2+1, '0') + string(length/2, '1'));
        
        int totOdd = 0;
        for (char c:stringN) {
            if ((c-'0')%2 == 1) totOdd++; 
        }
        if (2*totOdd == length) return n;
        
        int res;
        for (int i=length-1; i>=0; i--) {
            string firstPart = stringN.substr(0, i);
            string lastPart = stringN.substr(i+1);
            if ((stringN[i]-'0') < 9) {
                res = balanceInt(firstPart+to_string((stringN[i]-'0')+1)+lastPart, i);
                if (res != -1) return res; 
            }
            if ((stringN[i]-'0') < 8) {
                res = balanceInt(firstPart+to_string((stringN[i]-'0')+2)+lastPart, i);
                if (res != -1) return res;                 
            }            
        }
        
        return stoi('1' + string(length/2+1, '0') + string(length/2, '1'));  //handle case like 99->1001
    }
};