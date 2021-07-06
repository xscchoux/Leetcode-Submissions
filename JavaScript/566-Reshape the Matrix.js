/**
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(mat, r, c) {
    const rowNum = mat.length, colNum = mat[0].length;
    if (rowNum === r && colNum === c || r*c !== rowNum*colNum){
        return mat;
    }
    
    let res = new Array(new Array());
    for (let row=0; row<rowNum; row++){
        for (let col=0; col<colNum; col++){
            res[res.length-1].push(mat[row][col]);
            if ( (row*colNum + col+1)%c === 0 ){
                r-= 1
                if (r > 0) res.push(new Array());
            }
        }
    }
    return res;
};