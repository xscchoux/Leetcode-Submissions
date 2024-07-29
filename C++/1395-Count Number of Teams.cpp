class Solution {
public:
    int numTeams(vector<int>& rating) {
        multiset<int> m;
        int res = 0;
        int N = rating.size();
        vector<int> leftSmaller(N), leftLarger(N), rightSmaller(N), rightLarger(N);
        for (int i=0; i<N; i++) {
            auto it = m.lower_bound(rating[i]);
            leftSmaller[i] = distance(m.begin(), it);
            leftLarger[i] = i - leftSmaller[i];
            m.insert(rating[i]);
        }

        multiset<int> m2;
        for (int i=N-1; i>=0; i--) {
            auto it = m2.upper_bound(rating[i]);
            rightLarger[i] = distance(it, m2.end());
            rightSmaller[i] = N-i-1-rightLarger[i];
            m2.insert(rating[i]);

            res += leftSmaller[i]*rightLarger[i] + leftLarger[i]*rightSmaller[i];
        }

        return res;
    }
};