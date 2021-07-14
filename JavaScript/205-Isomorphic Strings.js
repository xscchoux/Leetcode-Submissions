/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    if (s.length !== t.length) return false;
    let hmap = new Map();
    let mapped = new Set();
    
    for (let i=0; i<s.length; i++){
        if (hmap.has(s[i])){
            if (t[i] !== hmap.get(s[i])) return false;
        }else{
            if (mapped.has(t[i])) return false;
            hmap.set(s[i], t[i]);
            mapped.add(t[i]);
        }
    }
    return true;
};