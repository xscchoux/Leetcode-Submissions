/**
 * @param {string} s
 * @param {string[]} d
 * @return {string}
 */
var findLongestWord = function(s, d) {
    let res = "";
    
    let isSub = (s1, s2) =>{
        let j = 0;
        for (let a of s1){
            if (a === s2[j]){
                j++;
                if (j === s2.length){
                    return true;
                }
            }
        }
        return j === s2.length;
    }
    
    for (let string of d){
        if (isSub(s, string)){
            if (string.length > res.length || (string.length === res.length && string < res)  ){
                res = string;
            }
        }
    }
    return res;
};