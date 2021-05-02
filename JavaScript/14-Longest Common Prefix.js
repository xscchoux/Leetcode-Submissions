/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 0) return "";
    
    for (let i=0; i<strs[0].length; i++){
        let curr = strs[0][i];
        for (let j=1; j<strs.length; j++){
            if (strs[j].length === i || strs[j][i] !== curr){
                return strs[0].substring(0,i);
            }
        }
    }
    return strs[0];
};