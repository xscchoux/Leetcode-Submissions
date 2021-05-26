/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    let stack = [];
    let operators = new Set(["+","-","*","/"]);
    
    for (let token of tokens){
        if (!operators.has(token)){
            stack.push(parseInt(token));
        }else{
            let num2 = stack.pop();
            let num1 = stack.pop();
            if (token === "+"){
                stack.push(num1+num2);
            }else if (token === "-"){
                stack.push(num1-num2);
            }else if (token === "*"){
                stack.push(num1*num2);
            }else{
                stack.push(parseInt(num1/num2));
            }
        }
    }
    return stack[0];
};