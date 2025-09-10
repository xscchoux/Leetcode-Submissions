// O(number of user*number of languages)
// Greedy, using unordered_set
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();  // number of users
        unordered_set<int> toBeTeached;  // users to be teached

        for (auto &f:friendships) {
            unordered_set<int> lan;
            bool canCommunicate = false;
            for (int l:languages[f[0]-1]) {
                lan.insert(l);
            }
            for (int l:languages[f[1]-1]) {
                if (lan.contains(l)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                toBeTeached.insert(f[0]-1);
                toBeTeached.insert(f[1]-1);
            }        
        }

        unordered_map<int, int> cnt;
        int maxCnt = 0;
        for (int user:toBeTeached) {
            for (int lan:languages[user]) {
                cnt[lan]++;
                maxCnt = max(maxCnt, cnt[lan]);
            }
        }

        return toBeTeached.size() - maxCnt;
    }
};


// All bitset, much faster
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();  // number of users
        vector<bitset<501>> bs(m);

        for (int i=0; i<m; i++) {
            for (int lan:languages[i]) {
                bs[i][lan] = 1;
            }
        }

        bitset<501> toBeTeached; 
        for (auto &f:friendships) {
            int u = f[0]-1, v = f[1]-1;
            if ((bs[u] & bs[v]).any()) continue;
            toBeTeached[u] = 1;
            toBeTeached[v] = 1;
        }

        if (toBeTeached.count() == 0) return 0;

        int maxCnt = 0;
        for (int lang=1; lang<=n; lang++) {
            int cnt = 0;
            for (int i=0; i<m; i++) {
                if (toBeTeached[i] && bs[i][lang] == 1) {
                    cnt++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }

        return toBeTeached.count() - maxCnt;
    }
};