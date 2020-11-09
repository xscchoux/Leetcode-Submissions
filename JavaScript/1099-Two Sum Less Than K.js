/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var twoSumLessThanK = function(A, K) {
    A.sort(function(a,b){return a-b;})
    
    let low = 0, high = A.length-1;
    
    let res = -1;
    
    while (low < high){
        let tmp = A[low] + A[high];
        if (tmp >= K){
            high -= 1;
        }
        else{
            res = Math.max(res, A[low]+A[high])
            low += 1;
        }
    }
    return res;
};