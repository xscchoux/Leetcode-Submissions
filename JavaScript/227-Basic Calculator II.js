/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    let stack = [];
    let operator = "+";
    let index = 0;
    while (index < s.length){
        if (s[index] === " "){
            index++;
            continue;
        }
        if (s[index] >= '0' && s[index] <= '9'){
            let num = "";
            while (index < s.length && s[index] >= '0' && s[index] <= '9'){
                num += s[index];
                index++;
            }
            num = parseInt(num);
            if (operator === '+'){
                stack.push(num);     
            } else if(operator === '-'){
                stack.push(-1*num);
            } else if(operator === '*'){
                let prev = stack.pop();
                stack.push(num*prev);
            } else if(operator === '/'){
                let prev = stack.pop();
                stack.push(parseInt(prev/num));  //parseInt returns the integer part for either negative or positive numbers
            }
        }
        else{
            operator = s[index];
            index++;
            continue;
        }
    }
    let res = 0;
    for (let s of stack){
        res += s;
    }
    return res;
};