/**
 * @param {number[]} piles
 * @return {boolean}
 */
var stoneGame = function(piles) {
    const N = piles.length;
    let memo = new Map();
    let dfs = (start, end)=>{
        if (start > end) return 0;
        if (memo.has(`${start}-${end}`)){
            return memo.get(`${start}-${end}`);
        }
        memo.set(`${start}-${end}`, Math.max(piles[start] - dfs(start+1, end), piles[end]-dfs(start, end-1)));
        return memo.get(`${start}-${end}`);
    }
    
    return dfs(0,N-1) > 0;
};