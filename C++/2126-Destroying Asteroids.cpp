class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        long long m = mass;
        for (int i=0; i<asteroids.size(); i++) {
            if (m < asteroids[i]) {
                return false;
            } else {
                m += asteroids[i];
            }
        }

        return true;
    }
};