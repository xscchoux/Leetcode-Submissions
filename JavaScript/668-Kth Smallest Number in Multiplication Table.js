/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(m, n, k) {
    
    let isEnough = (val) =>{
        let count = 0;
        for (let i=1; i<=m; i++){
            count += Math.min((val/i)|0, n);
        }
        return count >= k;
    }
        
    let left = 1, right = m*n;
    
    while (left +1 < right){
        let mid = left + ((right-left) >> 1);
        if (isEnough(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    if (isEnough(left)){
        return left;
    }else{
        return right;
    }
};