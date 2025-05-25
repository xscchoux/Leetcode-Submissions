// First AC
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int paired = 0, single = 0;

        unordered_map<string, int> visited;

        for (int i=0; i<words.size(); i++) {
            string &w = words[i];
            string newS = w;
            reverse(begin(newS), end(newS));
            if (visited.contains(newS)) {
                visited[newS]--;
                if (visited[newS] == 0) visited.erase(newS);
                paired += 4;
            } else {
                visited[w]++;
            }
        }

        for (auto &[k, v]:visited) {
            if (k[0] == k[1]) {
                single = 2;
                break;
            }
        }

        return paired + single;
    }
};


// Pretty fast
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int N = words.size();
        int cnt[26][26] = {0};

        int res = 0;
        for (auto &w:words) {
            int c1 = w[0] - 'a', c2 = w[1] - 'a';
            if (cnt[c2][c1]) {
                cnt[c2][c1]--;
                res += 4;
            } else {
                cnt[c1][c2]++;
            }
        }

        for (int i=0; i<26; i++) {
            if (cnt[i][i]) {
                res += 2;
                break;
            }
        }

        return res;
    }
};