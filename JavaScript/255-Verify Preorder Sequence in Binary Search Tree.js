/**
 * @param {number[]} preorder
 * @return {boolean}
 */
var verifyPreorder = function(preorder) {
    let min = Number.NEGATIVE_INFINITY;
    let stack = [Number.POSITIVE_INFINITY];
    
    for (let val of preorder){
        if (val < min){
            return false;
        }
        while (val > stack[stack.length-1]){
            min = stack.pop();
        }
        stack.push(val);
    }
    
    return true;
};