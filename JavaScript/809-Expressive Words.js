/**
 * @param {string} s
 * @param {string[]} words
 * @return {number}
 */
var expressiveWords = function(s, words) {
    let isStrechy = (w, word) =>{
        let sIdx = 0, wIdx = 0;
        const sLen = s.length, wLen = word.length;
        while (sIdx < sLen && wIdx < wLen){
            const currS = s[sIdx], currW = word[wIdx];
            if (currS !== currW) return false;
            let sCount = 0, wCount = 0;
            while (sIdx < sLen && s[sIdx] === currS){
                sCount++; sIdx++;
            }
            
            while (wIdx < wLen && word[wIdx] === currW){
                wCount++; 
                if (wCount > sCount) return false;
                wIdx++;
            }
            
            if (wCount < sCount && sCount < 3) return false;
        }
        if (sIdx < sLen || wIdx < wLen) return false;
        return true;
    }
    
    let res = 0;
    for (let word of words){
        if (isStrechy(s, word)) res++;
    }
    return res;
};