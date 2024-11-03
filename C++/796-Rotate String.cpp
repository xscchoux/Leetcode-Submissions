// O(n^2)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s == goal) return true;
        int N = s.size();
        
        for (int i=1; i<N; i++) {
            string newS = s.substr(i) + s.substr(0, i);
            if (newS == goal) return true;
        }

        return false;
    }
};


// O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string doubleS = s + s;

        size_t found = doubleS.find(goal);
        if (found == string::npos) return false;
        return true;
    }
};