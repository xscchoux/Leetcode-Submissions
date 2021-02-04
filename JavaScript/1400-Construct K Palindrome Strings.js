/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    if (s.length < k) return false;
    
    let charMap = new Map();
    for (let letter of s){
        if(charMap.has(letter)){
            charMap.set(letter, charMap.get(letter) + 1);
        }else{
            charMap.set(letter, 1);
        }
    }
    let oddCount = 0
    for (let val of charMap.values()){
        if (val%2 !== 0){
            oddCount += 1;
        }
    }
    
    return k>=oddCount;
};