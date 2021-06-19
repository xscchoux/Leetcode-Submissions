var TreeNode = function(start, end){
    this.left = null;
    this.right = null;
    this.start = start;
    this.end = end;
}

var MyCalendar = function() {
    this.root = null;
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function(start, end) {
    let insert = (start, end) =>{
        let head = this.root;
        while (true){
            if (head.end <= start){
                if (!head.right){
                    head.right = new TreeNode(start, end);
                    return true;
                }
                head = head.right;
            }else if (head.start >= end){
                if (!head.left){
                    head.left = new TreeNode(start, end);
                    return true;
                }
                head = head.left;
            }else{
                return false;
            }
        }
    }
    
    if (!this.root){
        this.root = new TreeNode(start, end);
        return true;
    }
    
    return insert(start, end);
};

/** 
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */