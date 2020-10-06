/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    res = [];
    let generate = (left, right, string) =>{
        if (left === n && right === n){
            res.push(string);
        }
        if (left < n){
            generate(left+1, right, string + "(");
        }
        if (left > right){
            generate(left, right+1, string + ")");
        }
    }
    generate(0,0,"");
    return res;
};