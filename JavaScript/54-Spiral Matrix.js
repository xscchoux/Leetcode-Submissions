/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (!matrix.length || !matrix[0].length ) return [];
    let left = 0, right = matrix[0].length-1, up = 0, down = matrix.length-1;
    let res = [];
    while (true){
        for (l = left; l <= right; l++){
            res.push(matrix[up][l]);
        }
        if (++up > down) break;
        
        for (u = up; u <= down; u++){
            res.push(matrix[u][right]);
        }
        if (--right < left) break;
        
        for (r = right; r >= left; r--){
            res.push(matrix[down][r]);
        }
        if (--down < up) break;
        
        for (d = down; d >= up; d--){
            res.push(matrix[d][left]);
        }
        if (++left > right) break;
    }
    return res;
};