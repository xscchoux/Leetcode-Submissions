/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var removeDuplicates = function(s, k) {
    let stack = [];
    for (let i=0; i<s.length; i++){
        if (!stack.length || s[i] != stack[stack.length-1][0]){
            stack.push([s[i], 1])
        }else{
            if ( stack[stack.length-1][1] + 1 === k){
                stack.pop();
            }else{
                stack[stack.length-1][1] += 1;
            }
        }
    }

    res = ""
    for (let x of stack){
        for (let i=0; i<x[1]; i++){
            res += x[0];
        }
    }
    return res;
};