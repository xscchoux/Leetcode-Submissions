class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
# time: O(n), space:O(n)
        if not s:
            return 0
        n = len(s)
        stack = []
        operator = '+'
        num = 0
        s.replace(' ','')
        for i in range(n):
            curr = s[i]
            if curr.isnumeric():
                num = num*10 + int(curr)
            if curr in ('*','+','-','/') or i == n-1:   # is an operator
                if operator == '+':
                    stack.append(num)
                elif operator == '-':
                    stack.append(-num)
                elif operator == '*':
                    prev = stack.pop()
                    stack.append(prev*num)
                else:
                    prev = stack.pop()
                    tmp = prev//num
                    if tmp < 0 and prev%num!=0:
                        tmp += 1
                    stack.append(tmp)
                operator = curr
                num = 0
        return sum(stack)

# solution 2
        return eval(s)