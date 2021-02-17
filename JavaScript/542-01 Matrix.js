/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var updateMatrix = function(matrix) {
    let row = matrix.length, col = matrix[0].length;
    
    let queue = new Array();
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (matrix[r][c] === 1){
                matrix[r][c] = Number.POSITIVE_INFINITY;
            } else{
                queue.push([r,c])
            }
        }
    }
    
    while (queue.length){
        let [currR, currC] = queue.shift();
        for (let [dr, dc] of [[0,1],[1,0],[0,-1],[-1,0]]){
            let newR = currR + dr, newC = currC + dc;
            if (0<=newR && newR<row && 0<=newC && newC<col && matrix[currR][currC] + 1 < matrix[newR][newC]){
                matrix[newR][newC] = matrix[currR][currC] + 1;
                queue.push([newR, newC]);
            }
        }
        
    }
    return matrix;
};