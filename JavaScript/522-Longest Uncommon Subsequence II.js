/**
 * @param {string[]} strs
 * @return {number}
 */
var findLUSlength = function(strs) {
    let count = new Map();
    for (let word of strs){
        count.set(word, (count.get(word)||0) + 1 );
    }
    
    strs = [...new Set(strs)];
    strs.sort(function(a, b){
        return b.length - a.length;
    })

    let seen = new Set();
    
    let isSub = (s1, s2) =>{
        let i=0, j=0;
        while (i<s1.length && j < s2.length){
            if (s1[i] === s2[j]) i++;
            j++;
        }
        return i === s1.length;
    }
    
    for (let i=0; i<strs.length; i++){
        if (count.get(strs[i]) === 1){
            let flag = true;
            for (let word of seen){
                if (isSub(strs[i], word)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                return strs[i].length;
            }
        }else{
            seen.add(strs[i])
        }
    }
    return -1;
};