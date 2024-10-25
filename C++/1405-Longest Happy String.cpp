// first try, lengthy but fast
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> arr;
        arr.push_back({a, 'a'});
        arr.push_back({b, 'b'});
        arr.push_back({c, 'c'});
        sort(arr.begin(), arr.end());

        int mx = min(arr.back().first, (arr[0].first + arr[1].first + 1)*2 );

        string remain;
        for (int i=0; i<2; i++) {
            for (int k = 0; k<arr[i].first; k++) {
                remain += arr[i].second;
            }
        }

        string res;
        vector<string> buckets((mx+1)/2);
        int mxCount = mx;
        for (int i=0; i<buckets.size(); i++) {
            if (mxCount >= 2) {
                buckets[i].push_back(arr[2].second);
                buckets[i].push_back(arr[2].second);
                mxCount -= 2;
            } else if (mxCount == 1) {
                buckets[i].push_back(arr[2].second);
                mxCount -= 1;
            }
        }

        int idx = 0;
        int Nb = buckets.size();
        for (int i=0; i<remain.size(); i++) {
            buckets[idx%Nb].push_back(remain[i]);
            idx++;
        }

        for (int i=0; i<buckets.size(); i++) {
            res += buckets[i];
        }

        return res;
    }
};



// O(n) greedy
// put char when
// 1. With highest freqency and the consecutive length of this char if < 2
// 2. When any other two chars has consecutive length of 2
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int N = a+b+c;
        string res;
        vector<int> cnt = {0, 0, 0};
        vector<int> s = {a, b, c};

        for (int i=0; i<N; i++) {
            for (int k=0; k<3; k++) {
                if ((cnt[k]<2 && s[k]>=s[(k+1)%3] && s[k]>=s[(k+2)%3])||(s[k]!=0 && (cnt[(k+1)%3]==2||cnt[(k+2)%3]==2) )) {
                    res += 'a'+k;
                    cnt[k]++;
                    cnt[(k+1)%3] = cnt[(k+2)%3] = 0;
                    s[k]--;
                    break;
                }
            }
        }
        return res;
    }
};