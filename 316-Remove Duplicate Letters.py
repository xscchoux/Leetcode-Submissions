class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
    # The conditions for deletion are:
    # The character is greater than the current characters
    # The character can be removed because it occurs later on
        
        last = dict()
        for i, c in enumerate(s):
            last[c] = i

        used = [False]*26
        stack = []
        
        for i, c in enumerate(s):
            if not used[ord(c)-ord('a')]:
                while stack and c < stack[-1] and i < last[stack[-1]]:
                    used[ord(stack.pop())-ord('a')] = False
                stack.append(c)
                used[ord(c)-ord('a')] = True
        
        return "".join(stack)