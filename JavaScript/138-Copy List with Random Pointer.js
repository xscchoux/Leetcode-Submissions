/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
    let hmap = new Map();
    
    let recurse = (node) =>{
        if (!node) return null;
        if (hmap.has(node)) return hmap.get(node);
        let copyNode = new Node(node.val, null, null);
        hmap.set(node, copyNode);
        copyNode.next = recurse(node.next);
        copyNode.random = recurse(node.random);
        return copyNode;
    }
    
    return recurse(head);
};