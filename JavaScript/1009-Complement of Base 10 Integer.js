/**
 * @param {number} N
 * @return {number}
 */
var bitwiseComplement = function(N) {
    return parseInt(N.toString(2).split('').map(e=>e==='1'? '0':'1').join(''), 2);
};