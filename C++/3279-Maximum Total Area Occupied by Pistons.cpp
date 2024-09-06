using LL = long long;
class Solution {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        int N = positions.size();
        map<int, vector<int>> hmap;
        int toAdd = 0;
        LL tot = 0;

        for (int i=0; i<N; i++) {
            tot += positions[i];
            if (directions[i] == 'U') {
                toAdd++;
                hmap[height-positions[i]].push_back(i);
                hmap[2*height-positions[i]].push_back(i);
            } else {
                toAdd--;
                hmap[positions[i]].push_back(i);
                hmap[height+positions[i]].push_back(i);                
            }
        }
        
        // toAdd = upward - downward

        LL res = tot;
        int currTime = 0;

        for (auto &[k, v]:hmap) {
            tot += (LL)(k-currTime)*toAdd;
            res = max(res, tot);
            for (int idx:v) {
                if (directions[idx] == 'U') {
                    directions[idx] = 'D';
                    toAdd -= 2;
                } else {
                    directions[idx] = 'U';
                    toAdd += 2;                    
                }
            }
            currTime = k;
        }

        return res;
    }
};




// without using vector, ingenious and faster solution
using LL = long long;
class Solution {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        int N = positions.size();
        map<int, int> hmap;
        LL toAdd = 0, tot = 0; // (count of upward)

        for (int i=0; i<N; i++) {
            if (directions[i] == 'U') {
                toAdd++;
                hmap[height-positions[i]]++;   // upward -> downward
                hmap[2*height-positions[i]]--; // downward -> upward
            } else {
                hmap[positions[i]]--;          // downward -> upward
                hmap[positions[i]+height]++;   // upward -> downward
            }
            tot += positions[i];
        }

        int currTime = 0;
        LL res = tot;
        for (auto &[k, v]:hmap) {
            tot += (k-currTime)*(2*toAdd-N);   // (2*toAdd - N) = count of upward - count of downward
            res = max(res, tot);
            toAdd -= v; // count of upward -= (current downward - current upload)
            currTime = k;
        }

        return res;
    }
};