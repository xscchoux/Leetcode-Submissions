/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    let res = [0];
    for (let i=1; i<=n; i++){
        res = res.concat((res.map(x=> x + Math.pow(2,i-1))).reverse());
    }
    return res;
};