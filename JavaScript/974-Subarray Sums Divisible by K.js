/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var subarraysDivByK = function(A, K) {
    let preSum = [0];
    let hmap = new Map();
    hmap.set(0, 1);
    
    for (let a of A){
        let curr = preSum[preSum.length-1] + a  //note that (-1%5) = -1 in JavaScript, therefore we use ((-1%5) + 5)%5 instead
        let num = ((curr%K)+K)%K
        preSum.push(num);
        hmap.set(num,  (hmap.get(num)||0)+1 )
    }
    
    let res = 0;
    for (let val of hmap.values()){
        res += val*(val-1)/2;
    }
    return res;
};