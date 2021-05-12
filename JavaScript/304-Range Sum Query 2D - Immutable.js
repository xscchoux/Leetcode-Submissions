/**
 * @param {number[][]} matrix
 */
var NumMatrix = function(matrix) {
    let row = matrix.length, col = matrix[0].length;
    this.dp = new Array(row+1).fill(0).map(x=>new Array(col+1).fill(0));
    for (let r=1; r<=row; r++){
        for (let c=1; c<=col; c++){
            this.dp[r][c] = matrix[r-1][c-1] + this.dp[r-1][c] + this.dp[r][c-1] - this.dp[r-1][c-1];
        }
    }
    
};

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {
    return this.dp[row2+1][col2+1] - this.dp[row1][col2+1] - this.dp[row2+1][col1] + this.dp[row1][col1];
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */