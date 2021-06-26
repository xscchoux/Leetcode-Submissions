/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let stack = path.split("/");
    let res = [];
    for (let i=0; i<stack.length; i++){
        if (stack[i] === ".."){
            if(res.length){
                res.pop();
            }
        }else if( stack[i] && stack[i] !== "."){
            res.push(stack[i]);
        }
    }
    return "/" + res.join("/");
};