/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {string[][]}
 */
var findLadders = function(beginWord, endWord, wordList) {
    let wordSet = new Set(wordList);
    if (!wordSet.has(endWord)) return [];
    if (wordSet.has(beginWord)) wordSet.delete(beginWord);
    
    let layer = new Map();
    layer.set(beginWord, [[beginWord]]);
    let res = [];

    while (layer.size){
        let used = new Set();
        let newLayer = new Map();
        for (let currWord of layer.keys()){
            for (let i=0; i<currWord.length; i++){
                for (let char of "abcdefghijklmnopqrstuvwxyz"){
                    let newWord = currWord.slice(0, i) + char + currWord.slice(i+1);
                    if (wordSet.has(newWord)){
                        used.add(newWord);
                        newLayer.set(newWord, (newLayer.get(newWord)||[]).concat(layer.get(currWord).map(x => x.concat(newWord))));
                    }
                }
            }
        }
        if (newLayer.has(endWord)){
            return newLayer.get(endWord);
        }
        wordSet = new Set([...wordSet].filter(x => !used.has(x)))
        layer = newLayer;
    }
    return [];
};