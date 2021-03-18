/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    const memo = new Map([[2,1],[3,2],[4,4],[5,6],[6,9]]);
    
    let dfs = (n) =>{
        if (memo.has(n)) return memo.get(n);
        return 3*dfs(n-3);
    }
    
    return dfs(n);
};