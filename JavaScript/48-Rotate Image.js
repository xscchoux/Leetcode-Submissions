/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

var rotate = function(matrix) {
    let N = matrix.length;
    
    for (let i=0; i<N; i++){
        for (let j=0; j<i; j++){
            let tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i]; 
            matrix[j][i] = tmp;
        }
    }
    
    for (let row of matrix){
        row = row.reverse();
    }
};