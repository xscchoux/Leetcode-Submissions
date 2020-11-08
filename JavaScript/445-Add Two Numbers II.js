/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let num1 = [], num2 = [];
    
    while (l1){
        num1.push(l1.val);
        l1 = l1.next;
    }
    while (l2){
        num2.push(l2.val);
        l2 = l2.next;
    }
    
    let sum = 0;
    let node = null;
    
    while (num1.length >0 || num2.length > 0 || sum){
        sum += num1.length > 0 ? num1.pop():0;
        sum += num2.length > 0 ? num2.pop():0;
        let newNode = new ListNode(sum%10);
        newNode.next = node;
        node = newNode;
        sum = Math.floor(sum/10);
    }
    return node;
};