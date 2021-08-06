/**
 * @param {number[]} nums
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var TreeNode = function(){
    this.children = new Array(2).fill(null);
    this.cnt = 0;
}

var countPairs = function(nums, low, high) {
    let root = new TreeNode();
    let length = 14;
    let res = 0;
    
    let insert = (num) =>{
        let node = root;
        for (let i = length; i>=0; i--){
            let currBit = (num>>i) & 1;
            if (!node.children[currBit]){
                node.children[currBit] = new TreeNode();
            }
            node = node.children[currBit];
            node.cnt++;
        }
    }
    
    let countSmaller = (num, limit) =>{
        let count = 0;
        let node = root;
        for (let j = length; j>=0; j--){
            let numBit = (num>>j) & 1, limitBit = (limit>>j) & 1;
            if (limitBit === 1){
                if (node.children[numBit]) count += node.children[numBit].cnt;
                node = node.children[1-numBit];
            }else{
                node = node.children[numBit];
            }
            if (node === null) break;
        }
        return count;
    }
    
    for (let num of nums){
        res += countSmaller(num, high+1) - countSmaller(num, low);
        insert(num);
    }
    return res;
};