/**
 * @param {string} s
 * @param {string[]} dict
 * @return {string}
 */
var addBoldTag = function(s, dict) {
    
    let wordDict = new Map();
    let inDict = new Array(s.length).fill(false);
    
    for (let word of dict){
        wordDict.set(word[0], [word].concat(wordDict.get(word[0])||[]) );
    }
    
    for (let i=0; i<s.length; i++){
        if (wordDict.has(s[i])){
            for (let string of wordDict.get(s[i])){
                if(string === s.substr(i, string.length)){
                    for(index = i; index<i+string.length; index++){
                        inDict[index] = true;
                    }
                }
            }
        }
    }
    
    let res = [];
    
    for (let i=0; i<s.length; i++){
        if (inDict[i] && (i==0 || !inDict[i-1])){
            res.push("<b>");
        }
        else if (!inDict[i] && i>0 && inDict[i-1]){
            res.push("</b>");
        }
        res.push(s[i]);
    }
    if (inDict[s.length-1]) res.push("</b>");
    
    return res.join("");
};