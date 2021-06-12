/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let arr = s.trimEnd().split(" ");
    return arr[arr.length-1].length;
};