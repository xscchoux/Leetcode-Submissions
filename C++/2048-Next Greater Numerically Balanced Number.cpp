// maximum beautiful number is 1224444, time complexity: O(122444-n)
class Solution {
public:
    bool isOK(vector<int>& cnt) {
        if (cnt[0] > 0) return false;
        for (int i=1; i<=9; i++) {
            if (cnt[i] > 0 && cnt[i] != i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int curr = n+1;

        while (true) {
            vector<int> cnt(10, 0);
            int tmp = curr;
            while (tmp > 0) {
                cnt[tmp%10]++;
                tmp /= 10;
            }

            if (isOK(cnt)) {
                return curr;
            }
            curr++;
        }

        return 0;
    }
};


// backtracking, much faster
class Solution {
public:
    int dfs(int n, int curr, int remainLength, vector<int>& count) {
        if (remainLength == 0) {
            if (curr <= n) return 0;
            for (int i=0; i<=9; i++) {
                if (count[i] > 0 && count[i] != i) return 0;
            }
            return curr;
        }

        int res = 0;
        for (int num=1; num<=9; num++) {
            if (count[num] < num && num - count[num] <= remainLength) {
                count[num]++;
                res = dfs(n, curr*10+num, remainLength-1, count);
                if (res > 0) return res;
                count[num]--;
            }
        }

        return 0;
    }
    int nextBeautifulNumber(int n) {
        string s = to_string(n);
        int sz = s.size();

        vector<int> count(10, 0);

        int result = 0;
        result = dfs(n, 0, sz, count);
        if (result > 0) return result;
        result = dfs(n, 0, sz+1, count);

        return result;
    }
};