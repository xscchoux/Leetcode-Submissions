/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
    let wordSet = new Set(wordList);
    if (!wordSet.has(endWord)) return 0;
    if (wordSet.has(beginWord)) wordSet.delete(beginWord);
    
    let queue1 = new Set([beginWord]), queue2 = new Set([endWord]);
    
    let step = 1
    while (queue1.size && queue2.size){
        if (queue1.size > queue2.size){
            [queue1, queue2] = [queue2, queue1];
        }
        let tmp = new Set();
        for (let currWord of queue1){
            for (let i=0; i<currWord.length; i++){
                for (let char of "abcdefghijklmnopqrstuvwxyz"){
                    let newWord = currWord.slice(0,i) + char +currWord.slice(i+1);
                    if (queue2.has(newWord)){
                        return step+1;
                    }
                    if (wordSet.has(newWord)){
                        wordSet.delete(newWord);
                        tmp.add(newWord);
                    }
                }
            }
        }
        queue1 = tmp;
        step += 1;
    }
    return 0;  
};