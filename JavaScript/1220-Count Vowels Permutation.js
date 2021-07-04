/**
 * @param {number} n
 * @return {number}
 */
var countVowelPermutation = function(n) {
    let [aCount, eCount, iCount, oCount, uCount] = new Array(5).fill(1)
    kMod = 10**9 + 7

    for (let i=1; i<n; i++){
        let aCountNew = (iCount + eCount + uCount)%kMod;
        let eCountNew = (aCount + iCount)%kMod;
        let iCountNew = (eCount + oCount)%kMod;
        let oCountNew = iCount;
        let uCountNew = (iCount + oCount)%kMod;

        [aCount, eCount, iCount, oCount, uCount] = [aCountNew, eCountNew, iCountNew, oCountNew, uCountNew];
    }
    return (aCount+eCount+iCount+oCount+uCount)%kMod;
};