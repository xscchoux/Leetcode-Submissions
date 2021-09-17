/**
 * @param {number} k
 * @param {number} digit1
 * @param {number} digit2
 * @return {number}
 */
var findInteger = function(k, digit1, digit2) {
    if (digit2 < digit1){
        [digit1, digit2] = [digit2, digit1];
    }
    let queue = [digit1, digit2];
    const limit = 2147483647;
    
    while (queue.length){
        let curr = queue.shift();
        if (0<curr && curr<=limit){
            if (curr > k && curr%k===0){
                return curr;
            }
            queue.push(10*curr+digit1);
            queue.push(10*curr+digit2);
        }
    }
    return -1;
};