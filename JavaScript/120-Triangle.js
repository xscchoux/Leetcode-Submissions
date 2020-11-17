/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    let row = triangle.length;
    
    for (let r=row-2; r>=0; r--){
        for (let c=0; c<=r; c++){
            triangle[r][c] += Math.min(triangle[r+1][c], triangle[r+1][c+1])
        }
    }
    
    return triangle[0][0];
};