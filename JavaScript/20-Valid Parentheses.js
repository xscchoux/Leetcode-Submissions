/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const hmap = {'(':')','{':'}','[':']'};
    stack = [];
    
    for (let char of s){
        if (stack.length>0 && hmap[stack[stack.length-1]] === char){
            stack.pop();
        }
        else{
            stack.push(char);
        }
    }
    return stack.length === 0;
};