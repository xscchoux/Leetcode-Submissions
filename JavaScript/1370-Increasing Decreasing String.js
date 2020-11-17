/**
 * @param {string} s
 * @return {string}
 */
var sortString = function(s) {
    let hmap = new Map();
    for (let char of s){
        hmap.set(char, (hmap.get(char)||0)+1);
    }
    let res = "";
    while (res.length < s.length){
        for (let char of 'abcdefghijklmnopqrstuvwxyz'){
            if (hmap.get(char)){
                res += char;
                hmap.set(char, hmap.get(char)-1);
            }
        }
        
        for (let char of 'zyxwvutsrqponmlkjihgfedcba'){
            if (hmap.get(char)){
                res += char;
                hmap.set(char, hmap.get(char)-1);
            }
        }
    }
    return res;
};