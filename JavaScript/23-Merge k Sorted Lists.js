/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if (lists.length < 1) return null;
    
    let mergeTwo = (one, two) =>{
        let dummy = new ListNode(0);
        let curr = dummy;
        while (one && two){
            if (one.val<=two.val){
                curr.next = new ListNode(one.val);
                one = one.next;
            } else{
                curr.next = new ListNode(two.val);
                two = two.next;
            }
            curr = curr.next;
        }
        curr.next = one || two;
        return dummy.next;
    }
    
    let merge = (lists) =>{
        if (lists.length <= 1) return lists;
        let arr = [];
        for (i=0; i<lists.length; i+=2){
            arr.push(mergeTwo(lists[i], lists[i+1]));
        }
        if (i < lists.length-1) arr.push(lists[lists.length-1])
        return merge(arr)
    }
    
    return merge(lists)[0] ? merge(lists)[0]:null
    
};