/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let hmap = new Map();
    for (let word of strs){
        let sortedS = [...word].sort().join("")
        if (!hmap.has(sortedS)){
            hmap.set(sortedS, []);
        }
        hmap.get(sortedS).push(word);
    }
    
    return [...hmap.values()];
};