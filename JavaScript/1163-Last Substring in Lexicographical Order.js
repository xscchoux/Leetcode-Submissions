/**
 * @param {string} s
 * @return {string}
 */
var lastSubstring = function(s) {
    let maxChar = s[0];
    for (i=1; i<s.length; i++){
        maxChar = (maxChar > s[i])? maxChar:s[i];
    }
    
    let charSet = new Set();
    for (i=0; i<s.length; i++){
        if (s[i] === maxChar){
            charSet.add(i);
        }
    }
    
    let length = 0;
    
    while (charSet.size>1){
        let nextCharMap = new Map();
        for (let index of charSet){
            if(index === s.length-1){
                continue;
            }
            if(charSet.has(index-length-1)){
                continue;
            }
            nextCharMap.set(s[index+1], (nextCharMap.get(s[index+1])||new Set()).add(index+1));
        }
        let keyArr = Array.from(nextCharMap.keys());
        charSet = nextCharMap.get( keyArr.reduce((max, item)=>{return (max>item)?max:item; },''));
        length++;
    }
    return s.substring([...charSet][0]-length);
};