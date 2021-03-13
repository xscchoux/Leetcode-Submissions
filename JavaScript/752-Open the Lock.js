/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target) {
    let deadendset = new Set(deadends);
    // edge case
    if(deadendset.has('0000')) return -1;
    deadendset.add('0000');
    
    let queue = [['0000',0]];
    
    function* findNxt(v) {
        for (let i=0; i<v.length; i++){
            const num = Number(v[i]);
            for (let change of [1, -1]){
                yield v.slice(0,i) + ((num+change)%10+10)%10  + v.slice(i+1);  
            }
        }
    }
    
    while (queue.length){
        const size = queue.length;
        for (let i=0; i<size; i++){
            let [curr, count] = queue.shift();
            if (curr === target) return count;
            let generator = findNxt(curr);
            while (true){
                let nxt = generator.next().value;
                if (!nxt) break;
                if (deadendset.has(nxt)) continue;
                deadendset.add(nxt);
                queue.push([nxt, count+1]);
            }
        }
    }
    return -1
};