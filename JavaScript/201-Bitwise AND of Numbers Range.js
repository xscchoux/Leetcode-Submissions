/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeBitwiseAnd = function(left, right) {
    while (right !== 0 && right > left){
        right = right&(right-1);
    }
    return right;
};