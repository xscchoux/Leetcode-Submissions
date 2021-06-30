/**
 * @param {number} n
 * @return {boolean}
 */
var isArmstrong = function(n) {
    let res = 0; len = Math.floor(Math.log10(n))+1;
    let tmp = n
    
    while (tmp > 0){
        res += Math.pow(tmp%10, len);
        tmp = Math.floor(tmp/10);
    }
    return res === n;
};