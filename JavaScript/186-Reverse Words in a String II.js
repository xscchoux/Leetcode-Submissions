/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseWords = function(s) {
    const N = s.length;
    s.reverse();
    let start = 0;
    
    // Array.prototype.slice returns a copy already. Array.prototype.splice modifies the original array
    
    for (let end = 0; end < N; end++){
        if (s[end] == " "){
            s.splice(start, end-start, ...s.slice(start, end).reverse() );
            start = end + 1;
        }
    }
    s.splice(start, N-start, ...s.slice(start, N).reverse());
};