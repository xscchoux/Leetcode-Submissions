/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if (digits.length <=0) return [];
    
    const hmap = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"};
    
    res = [];
    let str = ""
    let dfs = (i, val) =>{
        if (i === digits.length){
            res.push(val);
            return;
        }
        for (let char of hmap[digits[i]] ){
            dfs(i+1, val + char)
        }
    }
    dfs(0, "");
    
    return res;
};