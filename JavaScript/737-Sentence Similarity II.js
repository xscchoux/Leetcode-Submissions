/**
 * @param {string[]} sentence1
 * @param {string[]} sentence2
 * @param {string[][]} similarPairs
 * @return {boolean}
 */
var areSentencesSimilarTwo = function(sentence1, sentence2, similarPairs) {
    if (sentence1.length != sentence2.length) return false;
    let parent = new Map();
    for (let [start, end] of similarPairs){
        parent.set(start, start);
        parent.set(end, end);
    }
    
    let find = (x) =>{
        if (x !== parent.get(x)){
            parent.set(x, find(parent.get(x)));
        }
        return parent.get(x);
    }
    
    let union = (a, b) =>{
        parent.set(find(a), find(b));
    }
    
    for (let [start, end] of similarPairs){
        union(start, end);
    }
    
    for (let i=0; i<sentence1.length; i++){
        if (sentence1[i] !== sentence2[i]){
            if (!parent.has(sentence1[i]) || !parent.has(sentence2[i]) || find(sentence1[i])!==find(sentence2[i])){
                return false;
            }
        }
    }
    return true;
};