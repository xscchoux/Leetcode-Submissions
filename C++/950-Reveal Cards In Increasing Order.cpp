class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck));
        int N = deck.size();
        vector<int> res(N, 0);
        deque<int> dq;

        for (int i=0; i<N; i++) dq.push_back(i); 
        int currIdx = 0;
        while (!dq.empty()) {
            res[dq.front()] = deck[currIdx++];
            dq.pop_front();
            if (!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }

        return res;
    }
};