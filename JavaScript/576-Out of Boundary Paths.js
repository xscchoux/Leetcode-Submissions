/**
 * @param {number} m
 * @param {number} n
 * @param {number} maxMove
 * @param {number} startRow
 * @param {number} startColumn
 * @return {number}
 */
var findPaths = function(m, n, maxMove, startRow, startColumn) {
    
// DFS + memoization
    let memo = new Map();
    const kMod = Math.pow(10,9) + 7;
    
    let dfs = (r, c, N) =>{
        if (r < 0 || r >= m || c < 0 || c >= n) return 1;
        if (N === 0) return 0;
        if (memo.has(`${r}-${c}-${N}`)) return memo.get(`${r}-${c}-${N}`);
        
        let res = 0;
        res += dfs(r-1, c, N-1) + dfs(r+1, c, N-1) + dfs(r, c+1, N-1) + dfs(r, c-1, N-1);
        memo.set(`${r}-${c}-${N}`, res%kMod);
        return res%kMod
    }
    
    return dfs(startRow, startColumn, maxMove);

    
// DP
    let dp = new Array(m).fill().map(x=>new Array(n).fill(0));
    const kMod = Math.pow(10,9)+7;
    let count = 0;
    dp[startRow][startColumn] = 1;
    
    for (let i=0; i<maxMove; i++){
        let tmp = new Array(m).fill().map(x=>new Array(n).fill(0));
        for (let r=0; r<m; r++){
            for (let c=0; c<n; c++){
                if (r===0) count = (count + dp[r][c])%kMod;
                if (c===0) count = (count + dp[r][c])%kMod;
                if (r===m-1) count = (count + dp[r][c])%kMod;
                if (c===n-1) count = (count + dp[r][c])%kMod;
                
                if (r>0) tmp[r][c] = (tmp[r][c] + dp[r-1][c])%kMod;
                if (c>0) tmp[r][c] = (tmp[r][c] + dp[r][c-1])%kMod;
                if (r<m-1) tmp[r][c] = (tmp[r][c] + dp[r+1][c])%kMod;
                if (c<n-1) tmp[r][c] = (tmp[r][c] + dp[r][c+1])%kMod;
            }
        }
        dp = tmp;
    }
    return count;
};