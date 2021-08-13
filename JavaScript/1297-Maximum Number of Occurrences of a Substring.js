/**
 * @param {string} s
 * @param {number} maxLetters
 * @param {number} minSize
 * @param {number} maxSize
 * @return {number}
 */
var maxFreq = function(s, maxLetters, minSize, maxSize) {
    let hmap = new Map();
    let maxCount = 0;
    for (let i=minSize; i<=s.length; i++){
        let w = s.substring(i-minSize, i);
        setW = new Set(w);
        if (setW.size <= maxLetters){
            hmap.set(w, (hmap.get(w)||0) + 1);
            maxCount = Math.max(maxCount, hmap.get(w))
        }
    }
    return maxCount;
};