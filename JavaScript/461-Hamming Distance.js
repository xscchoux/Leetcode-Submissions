/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let xor = x^y, res = 0;
    while (xor){
        xor &= xor-1;
        res += 1;
    }
    return res;
};