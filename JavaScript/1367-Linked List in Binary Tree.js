/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSubPath = function(head, root) {
    let queue = [];
    queue.push(root);\
    
    const search = ( r, h ) => {
        if (h === null) return true;
        if (r === null) return false;
        if (h.val === r.val && (search(r.left, h.next) || search(r.right, h.next))){
            return true;
        } else{
            return false;
        }
    }
    
    while (queue.length > 0){
        let r = queue.shift();
        if (search(r, head) === true) return true;
        if (r.left !== null) queue.push(r.left);
        if (r.right !== null) queue.push(r.right);
    }
    return false;
};