/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaximumXOR = function(nums) {

// Bitwise Trie
    let res = 0;
    let root = new Map();
    
    for (const num of nums){
        let head = root, xor_head = root;
        let tmp = 0;
        for (let i=31; i>=0; i--){
            let curr = (num >> i) & 1;
            // insert
            if (!head.has(curr)){
                head.set(curr, new Map());
            }
            head = head.get(curr);
            
            // xor_head
            if (xor_head.has(curr^1)){
                xor_head = xor_head.get(curr^1);
                tmp += 1 << i
            }else{
                xor_head = xor_head.get(curr);
            } 
        }
        res = Math.max(tmp, res);
    }
    
    return res;
    
    
//  Bitwise Prefixes in HashSet
    let res = 0, mask = 0;
    
    for (i=31; i>=0; i--){
        mask += 1<<i;
        let prefixSet = new Set();
        for (let num of nums){
            prefixSet.add(num&mask);
        }
        let tmp = res | 1<<i;
        
        for (let prefix of prefixSet){
            if (prefixSet.has(prefix^tmp)){
                res = tmp;
                break;
            }
        }
    }
    return res;
};