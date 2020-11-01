/**
 * @param {number[][]} matrix
 * @return {number}
 */
var longestIncreasingPath = function(matrix) {
    if (!matrix || !matrix[0]) return 0;
    
    let memo = new Map();
    let row = matrix.length, col = matrix[0].length;
    let res = 1
    
    let dfs = (r, c, prev) => {
        let string = r.toString()+ " " + c.toString();
        if (memo.has(string)){
            return memo.get(string);
        }
        let curr = 1
        for (let [dr, dc] of [[0,1],[1,0],[0,-1],[-1,0]]){
            let newR = r + dr, newC = c + dc;
            if (newR<0 || newR>=row || newC<0 || newC>=col || matrix[newR][newC] >= matrix[r][c]){
                continue;
            }
            curr = Math.max(curr, 1+dfs(newR, newC, matrix[r][c]));
        }
        memo.set(string, curr);
        return memo.get(string);
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            res = Math.max(res, dfs(r,c, Number.POSITIVE_INFINITY))
        }
    }
    return res;
};