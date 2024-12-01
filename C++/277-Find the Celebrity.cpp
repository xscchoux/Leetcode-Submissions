/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // Think of all people as nodes in a DAG. Candidate will be the one of the end nodes in the DAG
        // (If there are more than one end nodes in the DAG, the answer is -1) 

        int candidate = 0;

        for (int i=1; i<n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        
        for (int i=0; i<n; i++) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) return -1;
        }

        return candidate;
    }
};