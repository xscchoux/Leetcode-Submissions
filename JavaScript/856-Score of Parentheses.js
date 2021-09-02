/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function(s) {
    //stack
    stack = [0];
    for (let i=0; i<s.length; i++){
        if (s[i] === "("){
            stack.push(0);
        }else{
            let v = stack.pop();
            stack[stack.length-1] += Math.max(2*v, 1);
        }
    }
    return stack.pop();
};