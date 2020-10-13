/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    let lastPos = new Map();
    let stack = [];
    let visited = new Set();
    
    for (const [index, element] of s.split('').entries()){
        lastPos[element] = index;
    }

    for (let i=0; i<s.length; i++){
        if (!visited.has(s[i])){
            while(stack.length > 0 && s[i]< stack[stack.length-1] && i-1 < lastPos[stack[stack.length-1]]){
                visited.delete(stack.pop());
            }
            stack.push(s[i]);
            visited.add(s[i])
        }
    }
    return stack.join("");
};