/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function(s, k) {
    const N = s.length;
    
    if (k===1){
        let smallest = s;
        for (let i=0; i<s.length; i++){
            tmp = s.substr(i) + s.substr(0,i);
            if (tmp < smallest){
                smallest = tmp
            }
        }
        return smallest;
    }else{
        return s.split("").sort(function(a, b){
            return a.localeCompare(b);
        }).join("");
    }
};