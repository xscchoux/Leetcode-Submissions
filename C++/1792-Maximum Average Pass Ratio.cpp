using TDII = tuple<double, int, int>;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<TDII> pq;
        double res = 0;
        for (auto &c:classes) {
            int u = c[0], v = c[1];
            if (u == v) res++;
            else {
                pq.emplace((double)(u+1)/(v+1) - (double)u/v, u, v);
            }
        }

        while (!pq.empty() && extraStudents-- > 0) {
            auto [val, u, v] = pq.top();
            pq.pop();
            pq.emplace((double)(u+2)/(v+2) - (double)(u+1)/(v+1), u+1, v+1);
        }

        int N = classes.size();

        while (!pq.empty()) {
            res += (double)get<1>(pq.top())/get<2>(pq.top());
            pq.pop();
        }

        return res/N;
    }
};



using TDII = tuple<double, int, int>;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<TDII> pq;
        double res = 0;
        for (auto &c:classes) {
            int u = c[0], v = c[1];
            if (u == v) res++;
            else {
                res += (double)u/v;
                pq.emplace((double)(u+1)/(v+1) - (double)u/v, u, v);
            }
        }

        while (!pq.empty() && extraStudents-- > 0) {
            auto [val, u, v] = pq.top();
            pq.pop();
            res -= (double)u/v;
            u++; v++;
            res += (double)u/v;
            pq.emplace((double)(u+1)/(v+1) - (double)u/v, u, v);
        }

        int N = classes.size();

        return res/N;
    }
};