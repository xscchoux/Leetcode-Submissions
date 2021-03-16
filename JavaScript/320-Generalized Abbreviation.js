/**
 * @param {string} word
 * @return {string[]}
 */
var generateAbbreviations = function(word) {
    let res = [];
    let dfs = (index, number, curr) =>{
        if (index === word.length){
            if (number > 0) curr += number.toString();
            res.push(curr);
            return 
        }
        dfs(index+1, number+1, curr)
        dfs(index+1, 0, curr + (number > 0 ? number.toString() : "") + word[index])
    }
    dfs(0, 0, "");
    return res
};