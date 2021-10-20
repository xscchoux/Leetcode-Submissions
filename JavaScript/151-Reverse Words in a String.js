/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(" ").filter(s => s.trim().length > 0).reverse().join(" ");
};