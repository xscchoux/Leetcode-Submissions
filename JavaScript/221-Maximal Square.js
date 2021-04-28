/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    let row = matrix.length, col = matrix[0].length;
    let res = 0;
    
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (matrix[r][c] === "0"){
                matrix[r][c] = 0;
            }else{
                if (r-1>=0 && c-1 >= 0){
                    matrix[r][c] = Math.min(matrix[r-1][c-1], matrix[r][c-1], matrix[r-1][c])+1;
                }else{
                    matrix[r][c] = parseInt(matrix[r][c]);
                }
                res = Math.max(matrix[r][c], res);
            }
        }
    }
    
    return res*res;
};