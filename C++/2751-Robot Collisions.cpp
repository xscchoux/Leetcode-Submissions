// My solution
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int N = positions.size();
        vector<tuple<int, int, char>> arr;
        for (int i=0; i<N; i++) arr.push_back({positions[i], healths[i], directions[i]});
        sort(arr.begin(), arr.end());
        unordered_map<int, int> hmap;
        vector<tuple<int, int, char>> stk;
        int ind = 0, minus = 0;

        while (ind < N) {
            int pos = get<0>(arr[ind]), health = (get<1>(arr[ind]))-minus, dir = get<2>(arr[ind]);
            minus = 0;
            if (dir == 'R') {
                stk.push_back({pos, health, dir});
                ind++;
            } else if (stk.empty()) {
                hmap[pos] = health;
                ind++;
            } else if (health > get<1>(stk.back()) ) {
                int cnt = 0;
                bool dead = false;
                while (!stk.empty() && (health-cnt) > get<1>(stk.back()) ) {
                    stk.pop_back();
                    cnt++;
                    if (health - cnt == 0) {
                        dead = true;
                        break;
                    }
                }
                if (dead) {
                    ind++;
                    continue;
                }
                if (stk.empty()) {
                    hmap[pos] = health-cnt;
                    ind++;
                } else {
                    minus = cnt;
                }
            } else if (health == get<1>(stk.back()) ) {
                stk.pop_back();
                ind++;
            } else if (health < get<1>(stk.back()) ) {
                auto [p, h, d] = stk.back();
                stk.pop_back();
                if (h-1 > 0) stk.push_back({p, h-1, d});
                ind++;
            }
        }

        for (int i=0; i<stk.size(); i++) {
            hmap[get<0>(stk[i])] = get<1>(stk[i]);
        }

        vector<int> res;
        for (int i=0; i<positions.size(); i++) {
            if (hmap.find(positions[i]) != hmap.end()) {
                res.push_back(hmap[positions[i]]);
            }
        }

        return res;
    }
};




// Clever and concise solution
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int N = positions.size();
        vector<int> ind(N);
        for (int i=0; i<N; i++) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> stk;
        for (int i=0; i<N; i++) {
            int idx = ind[i];
            if (directions[idx] == 'R') {
                stk.push_back(idx);
            } else {
                // clever way to handle all collisions in a while loop
                while (!stk.empty() && healths[idx] > 0) {
                    if (healths[idx] > healths[stk.back()]) {
                        healths[idx]--;
                        healths[stk.back()] = 0;
                        stk.pop_back();
                    } else if (healths[idx] == healths[stk.back()]) {
                        healths[idx] = 0;
                        healths[stk.back()] = 0;
                        stk.pop_back();
                    } else {
                        healths[idx] = 0;
                        healths[stk.back()]--;                    
                    }
                }
            }
        }
        
        vector<int> res;
        for (int i=0; i<N; i++) {
            if (healths[i] > 0) res.push_back(healths[i]);
        }

        return res;
    }
};