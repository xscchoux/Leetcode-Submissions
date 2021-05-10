/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var numWays = function(n, k) {
    if (k === 0 || (n > 2 && k === 1) ){
        return 0;
    }
    
    let same = 0, diff = k;
    
    for (let i = 1; i < n; i++){
        let tmp = diff;
        diff = (diff + same)*(k-1);
        same = tmp;
    }
    
    return same + diff;
};