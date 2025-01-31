// First AC
class Solution {
public:
    vector<vector<int>> res;
    int oddN, evenN, N;
    void dfs(vector<int>& odd, vector<int>& even, int bitOdd, int bitEven, vector<int>& tmp) {
        if (tmp.size() == N) {
            res.push_back(tmp);
            return;
        }
        if (tmp.size()%2 == 0) {
            for (int i=0; i<odd.size(); i++) {
                if (bitOdd & (1<<i)) continue;
                tmp.push_back(odd[i]);
                dfs(odd, even, bitOdd^(1<<i), bitEven, tmp);
                tmp.pop_back();
            }
        } else {
            for (int i=0; i<even.size(); i++) {
                if (bitEven & (1<<i)) continue;
                tmp.push_back(even[i]);
                dfs(odd, even, bitOdd, bitEven^(1<<i), tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(int n) {
        vector<int> odd, even;
        N = n;
        for (int i=1; i<=n; i++) {
            if (i%2) odd.push_back(i);
            else even.push_back(i);
        }
        this->oddN = odd.size();
        this->evenN = even.size();

        vector<int> tmp;
        if (n%2) {
            int bitOdd = 0, bitEven = 0;
            dfs(odd, even, bitOdd, bitEven, tmp);
        } else {
            int bitOdd = 0, bitEven = 0;
            dfs(odd, even, bitOdd, bitEven, tmp);
            bitOdd = 0;
            bitEven = 0;
            dfs(even, odd, bitEven, bitOdd, tmp);            
        }
        sort(begin(res), end(res));
        return res;
    }
};

// Better, even without sorting
class Solution {
public:
    vector<vector<int>> res;
    int N;
    void dfs(int idx, int bitmap, vector<int>& tmp) {
        if (idx == N) {
            res.push_back(tmp);
            return;
        }
        for (int i=0; i<N; i++) {
            if (bitmap & (1<<i)) continue; // used
            if (!tmp.empty() && (tmp.back()%2) == (i+1)%2 ) continue; 
            tmp.push_back(i+1);
            dfs(idx+1, bitmap^(1<<i), tmp);
            tmp.pop_back();
        }
    }

    vector<vector<int>> permute(int n) {
        vector<int> tmp;
        int bitmap = 0;
        N = n;
        dfs(0, bitmap, tmp);
        return res;
    }
};