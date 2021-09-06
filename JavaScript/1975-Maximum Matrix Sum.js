/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function(matrix) {
    let row = matrix.length, col = matrix[0].length;
    let res = 0, bad = 0, absMin = Number.POSITIVE_INFINITY;
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            let absNum = Math.abs(matrix[r][c]);
            res += absNum;
            if (matrix[r][c] < 0) bad++;
            absMin = Math.min(absMin, absNum);
        }
    }
    
    return bad%2 ? res-2*absMin : res;
};