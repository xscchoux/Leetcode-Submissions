/**
 * @param {string} palindrome
 * @return {string}
 */
var breakPalindrome = function(palindrome) {
    if (palindrome.length === 1) return "";
    
    for (let i=0; i < palindrome.length>>1; i++){
        if (palindrome[i] !== "a"){
            palindrome = palindrome.substring(0, i) + "a" + palindrome.substring(i+1);
            return palindrome;
        }
    }
    palindrome = palindrome.substring(0, palindrome.length - 1) + "b";
    return palindrome;
};