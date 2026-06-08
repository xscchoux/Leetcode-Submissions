// first AC, lengthy but still fast
class Solution {
public:
    long long dp[16][2][3][10];  // dp[index][isLimit][prevStatus][prevNum]
    int getStatus(int idx, int num, int prevNum) {
        if (idx == 0) return 1;
        if (num > prevNum) return 2;
        else if (num == prevNum) return 1;
        else return 0;
    }
    // status 0:smaller than prev num, 1: equal to prev num, 2: greater than prev num
    long long dfs(int idx, int length, string& limitString, int isLimit, int prevStatus, int prevNum) {
        if (idx == length) {
            return 0;
        }

        if (dp[idx][isLimit][prevStatus][prevNum] != -1) return dp[idx][isLimit][prevStatus][prevNum];

        long long cnt = 0;
        if (prevStatus == 1) {
            if (isLimit) {
                int upperLimit = limitString[idx]-'0';
                for (int num = (idx == 0?1:0); num <= upperLimit; num++) {
                    cnt += dfs(idx+1, length, limitString, (num==upperLimit)?1:0, getStatus(idx, num, prevNum), num);
                }
            } else {
                for (int num = (idx == 0?1:0); num <= 9; num++) {
                    cnt += dfs(idx+1, length, limitString, 0, getStatus(idx, num, prevNum), num);
                }
            }
        } else if (prevStatus == 0) {
            if (isLimit) {
                int upperLimit = limitString[idx]-'0';
                for (int num = (idx == 0?1:0); num <= upperLimit; num++) {
                    if (num > prevNum) {
                        if (num == upperLimit) {
                            if (idx == length-1) cnt++;
                            else {
                                cnt += stoll(limitString.substr(idx+1)) + 1;
                            }
                        } else {
                            cnt += pow(10, length-idx-1);
                        }
                    }
                    cnt += dfs(idx+1, length, limitString, (num==upperLimit)?1:0, getStatus(idx, num, prevNum), num);
                }
            } else {
                for (int num = (idx == 0?1:0); num <= 9; num++) {
                    if (num > prevNum) cnt += pow(10, length-idx-1);
                    cnt += dfs(idx+1, length, limitString, 0, getStatus(idx, num, prevNum), num);
                }
            }
        } else {
            if (isLimit) {
                int upperLimit = limitString[idx]-'0';
                for (int num = (idx == 0?1:0); num <= upperLimit; num++) {
                    if (num < prevNum) {
                        if (num == upperLimit) {
                            if (idx == length-1) cnt++;
                            else {
                                cnt += stoll(limitString.substr(idx+1)) + 1;
                            }
                        } else {
                            cnt += pow(10, length-idx-1);
                        }
                    }
                    cnt += dfs(idx+1, length, limitString, (num==upperLimit)?1:0, getStatus(idx, num, prevNum), num);
                }
            } else {
                for (int num = (idx == 0?1:0); num <= 9; num++) {
                    if (num < prevNum) cnt += pow(10, length-idx-1);
                    cnt += dfs(idx+1, length, limitString, 0, getStatus(idx, num, prevNum), num);
                }
            }
        }
        return dp[idx][isLimit][prevStatus][prevNum] = cnt;
    }
    long long cal(long long num) {
        
        // don't use digits = log10(num) + 1 here because log10 lacks accuracy

        int digits = to_string(num).length();
        long long res = 0;
        for (int d=3; d <= digits; d++) {
            string numString = to_string(pow(10, d)-1), limitNum = to_string(num);
            if (d < digits) {
                memset(dp, -1, sizeof(dp));
                res += dfs(0, d, numString, 1, 1, 0);
            } else {
                memset(dp, -1, sizeof(dp));
                res += dfs(0, d, limitNum, 1, 1, 0);
            }
        }
        return res;
    }

    long long totalWaviness(long long num1, long long num2) {
        long long res2 = cal(num2);
        long long res1 = 0;
        if (num1 - 1 > 0) res1 = cal(num1-1);
        res2 -= res1;
        return (long long)(res2);
    }
};


// Use `isLeadZero` and store the sum of previous scores in DP 
class Solution {
public:
    long long dp[2][16][3][10][20][2];  // dp[is limit][idx][previous status][previous num][previous score][is lead zero]
 
    int getStatus(int idx, int num, int prevNum, int isLeadZero) {
        if (isLeadZero) return 1; 
        if (num > prevNum) return 2;
        else if (num == prevNum) return 1;
        else return 0;
    }

    // status 0:smaller than prev num, 1: equal to prev num, 2: greater than prev num
    long long dfs(int idx, string& limitString, int isLimit, int prevStatus, int prevNum, int score, int isLeadZero) {
        if (idx == limitString.size()) {
            return score;
        }
        // cout <<"prevNum = " << prevNum << " score = " << score << endl;
        if (dp[isLimit][idx][prevStatus][prevNum][score][isLeadZero] != -1) {
            return dp[isLimit][idx][prevStatus][prevNum][score][isLeadZero];
        }
        
        long long res = 0;
        int upperLimit = isLimit?(limitString[idx]-'0'):9;
        for (int num = 0; num <= upperLimit; num++) {
            int nxtLeadZero = (isLeadZero && num == 0);
            int nxtLimit = isLimit && (num == upperLimit);  // note that we don't need to consider isLeadZero here
            
            // check if this is a turning point and it adds waviness
            int cnt = 0;  // cause waviness?
            if (prevStatus == 0 && num > prevNum) cnt = 1;
            if (prevStatus == 2 && num < prevNum) cnt = 1;

            res += dfs(idx+1, limitString, nxtLimit, getStatus(idx, num, prevNum, isLeadZero), num, score+cnt, nxtLeadZero);
        }

        return dp[isLimit][idx][prevStatus][prevNum][score][isLeadZero] = res;
    }

    long long cal(long long num) {
        string limitString = to_string(num);
        int digitLen = limitString.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, limitString, 1, 1, 0, 0, 1);
    }

    long long totalWaviness(long long num1, long long num2) {
        return cal(num2) - cal(num1 - 1);
    }
};

