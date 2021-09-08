/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) {
    let tot = 0;
    s = s.split("")
    
    for (let i=shifts.length-1; i>=0; i--){
        tot += shifts[i];
        s[i] = String.fromCharCode(97 + (s[i].charCodeAt(0) + tot - 97)%26);
    }
    
    return s.join("");
};