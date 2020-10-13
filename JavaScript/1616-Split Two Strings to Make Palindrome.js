/**
 * @param {string} a
 * @param {string} b
 * @return {boolean}
 */
var checkPalindromeFormation = function(a, b) {
    let start = 0, end = a.length-1;
    while (start < end && a[start] === b[end]){
        start++;end--;
    }
    let s1 = a.substring(start,end+1), s2 = b.substring(start,end+1);
    
    start = 0, end = a.length-1;
    while (start < end && b[start] === a[end]){
        start++; end--;
    }
    let s3 = b.substring(start,end+1), s4 = a.substring(start,end+1);
    
    for (let s of [s1,s2,s3,s4]){
        if (s.split("").reverse().join("") === s){
            return true;
        }
    }
    return false;
};