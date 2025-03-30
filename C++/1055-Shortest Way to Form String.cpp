// Naive O(n^2) solution
class Solution {
public:
    int shortestWay(string source, string target) {
        int Nt = target.size(), Ns = source.size();
        int ind = 0, count = 0;
        while (ind < Nt) {
            bool canFind = false;
            for (int j=0; j<Ns; j++) {
                if (source[j] == target[ind]) {
                    ind++;
                    canFind = true;
                }
                if (ind == Nt) return count+1; 
            }
            if (!canFind) return -1;
            count++;
        }
        return count;
    }
};


// clever binary search solution
class Solution {
public:
    int shortestWay(string source, string target) {
        int Nt = target.size(), Ns = source.size();
        int count = 0;
        vector<vector<int>> indexes(26);

        for (int i=0; i<Ns; i++) {
            indexes[source[i]-'a'].push_back(i);
        }

        int preIdx = -1;
        for (int i=0; i<Nt; i++) {
            int currIdx = target[i] - 'a';
            if (indexes[currIdx].empty()) return -1;
            auto it = upper_bound(begin(indexes[currIdx]), end(indexes[currIdx]), preIdx);
            if (it == indexes[currIdx].end()) {
                count++;
                preIdx = indexes[currIdx][0];
            } else {
                preIdx = *it;
            }
        }

        return count+1;

    }
};