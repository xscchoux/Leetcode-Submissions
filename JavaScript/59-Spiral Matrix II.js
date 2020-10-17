/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    matrix = new Array(n);
    for (let i=0; i<matrix.length; i++){
        matrix[i] = new Array(n);
    }
    let left = 0, right = n-1, up = 0, down = n-1;
    count = 1
    while (true){
        for (l = left; l <= right; l++){
            matrix[up][l] = count++;
        }
        if (++up > down) break;
        
        for (u = up; u <= down; u++){
            matrix[u][right] = count++;
        }
        if (--right < left) break;
        
        for (r = right; r >= left; r--){
            matrix[down][r] = count++;
        }
        if (--down < up) break;
        
        for (d = down; d >= up; d--){
            matrix[d][left] = count++;
        }
        if (++left > right) break;
    }
    return matrix;
};