using LL = long long;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<LL> pq;
        LL res = 0;
        for (int g:gifts) {
            pq.push(g);
            res += g;
        }
        
        while (k-- > 0) {
            int num = pq.top();
            pq.pop();
            res -= (num-sqrt(num));   // num-sqrt(num) results in a double because of type promotion
            pq.push(sqrt(num));  // Implicit Conversion from double to long long
        }

        return res;
    }
};