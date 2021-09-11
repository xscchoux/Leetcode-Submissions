/**
 * @param {number[][]} mat
 * @param {number} target
 * @return {number}
 */
var minimizeTheDifference = function(mat, target) {
    const row = mat.length, col = mat[0].length;
    let memo = new Map();
    for (let x of mat){
        x.sort(function(a,b){return a-b;})
    }
    
    let dp = (rowIdx, remain) =>{
        if (memo.has(`${rowIdx}-${remain}`)){
            return memo.get(`${rowIdx}-${remain}`);
        }
        
        if (rowIdx === row){
            return Math.abs(remain);
        }
        
        let ans = Number.POSITIVE_INFINITY;
        for (let i=0; i<col; i++){
            if (i>0 && mat[rowIdx][i] === mat[rowIdx][i-1]) continue;
            ans = Math.min(ans, dp(rowIdx+1, remain-mat[rowIdx][i]));
            if (ans === 0) return 0;
            if (remain-mat[rowIdx][i] < 0) break;
        }
        memo.set(`${rowIdx}-${remain}`, ans);
        return ans;
    }
    return dp(0, target);
};