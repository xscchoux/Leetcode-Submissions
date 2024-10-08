class Solution {
public:
    int minSwaps(string s) {
        if (s.empty()) return 0;
        int N = s.size(), res = 0;
        stack<char> stk;
        for (int i=0; i<N; i++) {
            if (s[i] == '[') {
                stk.push('[');
            } else {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    res++;
                    stk.push('[');
                }
            }
        }

        return res;
    }
};


// faster
class Solution {
public:
    int minSwaps(string s) {
        if (s.empty()) return 0;
        int N = s.size(), imbalanced = 0; // imbalanced: number of closing brackets (not paired)
        stack<char> stk;
        for (int i=0; i<N; i++) {
            if (s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    imbalanced++;
                }
            }
        }
        
        // Ex: if imbalanced is 5, we need at least (5+1)/2 swaps, ]]]]]  ->  [][][

        return (imbalanced+1)/2;
    }
};