/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    let memo = new Map();
    let dfs = (n) =>{
        if (n<=1) return 1;
        if (memo.has(n)) return memo.get(n);
        let res = 0;
        for (let i=0; i<n; i++){
            res += dfs(i)*dfs(n-i-1);
        }
        memo.set(n, res);
        return res;
    }
    return dfs(n);
};