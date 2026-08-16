class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3);
        for (int stone:stones) count[stone%3]++;
        
        vector<int> case1 = count;
        int tot = 0;
        if (case1[1] > 0) {
            case1[1]--;
            if (!win(1, case1, 0)) return true;
        }
        
        tot = 0;
        vector<int> case2 = count;
        if (case2[2] > 0) {
            case2[2]--;
            if (!win(2, case2, 0)) return true;
        }
        
        return false;
    }
    
    bool win(int sum, vector<int>& arr, int isAlice) {
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            return (isAlice == 1)?false:true;
        }
        // the most difficult part of this problem: best strategy is to pick stone with stone%3 == 0 first
        if (arr[0] > 0) {
            arr[0]--;
            if (!win(sum, arr, 1-isAlice)) return true;
        } else if (sum%3 == 1 && arr[1] > 0) {
            arr[1]--;
            if (!win(sum+1, arr, 1-isAlice)) return true;
        } else if (sum%3 == 2 && arr[2] > 0) {
            arr[2]--;
            if (!win(sum+2, arr, 1-isAlice)) return true;            
        }
        
        return false;
    }
};



// https://leetcode.cn/problems/stone-game-ix/solutions/1029063/guan-jian-zai-yu-qiu-chu-hui-he-shu-by-e-mcgv/
class Solution {
public:
    int N;
    bool check(vector<int> cnt) {
        if (cnt[1] == 0) {
            return false;
        }

        cnt[1]--;
        int rounds = 1 + min(cnt[1], cnt[2])*2 + cnt[0];
        if (cnt[1] > cnt[2]) {
            rounds++;
        }

        return rounds < N && rounds%2 == 1;
    }
    bool stoneGameIX(vector<int>& stones) {
        this->N = stones.size();
        vector<int> cnt(3, 0);
        for (int stone:stones) {
            cnt[stone%3]++;
        }

        vector<int> cnt2 = {cnt[0], cnt[2], cnt[1]};

        return check(cnt) || check(cnt2);

    }
};