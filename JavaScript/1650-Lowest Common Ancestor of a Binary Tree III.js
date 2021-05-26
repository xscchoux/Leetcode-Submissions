/**
 * // Definition for a Node.
 * function Node(val) {
 *    this.val = val;
 *    this.left = null;
 *    this.right = null;
 *    this.parent = null;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var lowestCommonAncestor = function(p, q) {
    while (p.parent){
        let tmp = p.parent;
        p.parent = null;
        p = tmp;
    }
    
    while (q){
        if (!q.parent){
            return q;
        }else{
            q = q.parent;
        }
    }
};