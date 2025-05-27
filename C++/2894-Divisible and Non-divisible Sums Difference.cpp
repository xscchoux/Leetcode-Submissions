class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisibleCnt = n/m;

        return n*(n+1)/2 - (divisibleCnt+1)*m*divisibleCnt;
    }
};