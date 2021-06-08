/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findMode = function(root) {
    let res = new Array(), stack = new Array();
    let preNode = null, count = 0, maxCount = 0;
    
    
    while (true){
        while (root){
            stack.push(root);
            root = root.left;
        }
        if (stack.length){
            root = stack.pop();
            if (preNode && root.val !== preNode.val){
                if (count > maxCount){
                    res = [preNode.val];
                    maxCount = count;
                }else if(count === maxCount){
                    res.push(preNode.val)
                }
                count = 1;
            }else{
                count += 1;
            }
            preNode = root;
            root = root.right;
        }else{
            break;
        }
    }
    
    if (count > maxCount){
        res = [preNode.val];
    }else if(count === maxCount){
        res.push(preNode.val);
    }
    
    return res;
};