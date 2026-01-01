class Leaderboard {
public:
    unordered_map<int, int> hmap; // id:score
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (hmap.contains(playerId)) {
            hmap[playerId] += score;
        } else {
            hmap[playerId] = score;
        }
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<>> pq;
        int sum = 0;
        for (auto &[_, v]:hmap) {
            pq.push(v);
            sum += v;
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return sum;
    }
    
    void reset(int playerId) {
        hmap[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */