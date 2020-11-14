/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nextLargerNodes = function(head) {
    let arr = [];
    let stack = [];
    
    while (head){
        arr.push(head.val);
        head = head.next;
    }
    
    let res = new Array(arr.length).fill(0);
    
    for (let i=0; i<arr.length; i++){
        while(stack.length && arr[i] > arr[stack[stack.length-1]]){
            res[stack.pop()] = arr[i];
        }
        stack.push(i);
    }
    return res;
};