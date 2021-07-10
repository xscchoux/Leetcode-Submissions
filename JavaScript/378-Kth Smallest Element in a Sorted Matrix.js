/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    let row = matrix.length, col = matrix[0].length;

    let left = matrix[0][0], right = matrix[row-1][col-1];
    
    let countSmallerEqual = (target) =>{
        let r = row-1, c = 0;
        let res = 0;
        while (r >= 0 && c < col){
            if (matrix[r][c] <= target){
                res += r+1;
                c += 1;
            }else{
                r-= 1;
            }
        }
        return res;
    }
    
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        if ( countSmallerEqual(mid) < k ){
            left = mid;
        }else{
            right = mid;
        }
    }
    if (countSmallerEqual(left) >= k){
        return left;
    }else{
        return right;
    }
};