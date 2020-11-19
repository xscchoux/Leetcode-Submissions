
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
# stack
        stack = []
        
        index = 0
        while index < len(s):
            if s[index].isdigit():
                nums = ""
                while s[index].isdigit():
                    nums = nums + s[index]
                    index += 1
                stack.append(nums)
            elif s[index] == '[':
                index += 1
                continue
            elif s[index].isalpha():
                char = ""
                while index < len(s) and s[index].isalpha():
                    char = char + s[index]
                    index += 1
                stack.append(char)
            else:
                string = ""
                while stack and stack[-1].isalpha():
                    string = stack.pop() + string
                if stack and stack[-1].isdigit():
                    number = int(stack.pop())
                    stack.append(number*string)
                else:
                    stack.append(string)
                index += 1
            
        return "".join(stack)


# DFS
        index = 0
        N = len(s)
        
        def dfs(index):
            string = ""
            while index < len(s):
                if s[index].isdigit():
                    num = ""
                    while s[index].isdigit():
                        num += s[index]
                        index += 1
                    num = int(num)
                elif s[index] == "[":
                    index += 1
                    newString, newIndex = dfs(index)
                    string += num*newString
                    index = newIndex
                elif s[index].isalpha():
                    while index < len(s) and s[index].isalpha():
                        string += s[index]
                        index += 1
                else:
                    return string, index+1

            return string
        
        return dfs(0)  