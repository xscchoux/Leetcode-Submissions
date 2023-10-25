// Iterative
class Solution {
public:
    int kthGrammar(int n, int k) {
        int flip = 0;
        k -= 1;
        for (int i=n-1; i>=0; i--){
            if (pow(2, i) <= k){
                k -= pow(2, i);
                flip += 1;
            }
        }
        if (flip%2 == 0) return 0;
        return 1;
    }
};

// Recursive
class Solution {
public:
    int dfs(int row, int idx){
        if (idx==0) return 0;
        int rowNum = pow(2, row-1);
        if (idx >= rowNum/2){
            return 1-dfs(row-1, idx-rowNum/2);
        }else {
            return dfs(row-1, idx);
        }
    }
    
    int kthGrammar(int n, int k) {
        return dfs(n, k-1);
    }
};