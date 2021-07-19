/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    const row = points.length, col = points[0].length;
    let prev = points[0];
    
    let leftMax = (arr) =>{
        let left = [arr[0]].concat(new Array(col-1).fill(0));
        for (let i=1; i<col; i++){
            left[i] = Math.max(arr[i], left[i-1]-1);
        }
        return left;
    }
    
    let rightMax = (arr) =>{
        let right = new Array(col-1).fill(0).concat([arr[col-1]]);
        for (let i=col-2; i>=0; i--){
            right[i] = Math.max(arr[i], right[i+1]-1);
        }
        return right;
    }
    
    for (let r=1; r<row; r++){
        let leftArr=leftMax(prev), rightArr=rightMax(prev);
        let curr = new Array(col).fill(0);
        for (let c=0; c<col; c++){
            curr[c] = points[r][c] + Math.max(leftArr[c], rightArr[c]);
        }
        prev = curr;
    }
    
    return Math.max(...prev);
};