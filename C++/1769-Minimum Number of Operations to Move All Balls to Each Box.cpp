class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
        int N = boxes.size();
        for (int i=0; i<N; i++) {
            int tot = 0;
            for (int j=0; j<N; j++) {
                if (i==j) continue;
                if (boxes[j] == '1') tot += abs(i-j);
            }
            res.push_back(tot);
        }
        return res;
    }
};


// O(n) solution, sum of moves
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int N = boxes.size();
        vector<int> res(N), prefix(N+1);
        int cnt = 0, distSum = 0;
        for (int i=0; i<N; i++) {
            distSum += cnt;
            prefix[i+1] = distSum;
            cnt += (boxes[i] == '1'?1:0);
        }

        cnt = 0;
        distSum = 0;
        for (int i=N-1; i>=0; i--) {
            distSum += cnt;
            res[i] = distSum + prefix[i+1];
            cnt += (boxes[i] == '1'?1:0);
        }
        return res;
    }
};