class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        
        if s == goal:
            return len(s) != len(set(s))
        
        cnt = 0
        first = -1
        second = -1
        for i in range(len(s)):
            if s[i] != goal[i]:
                if first == -1:
                    first = i
                elif second == -1:
                    second = i
                else:
                    return False
        
        if second == -1:
            return False
        
        return s[first] == goal[second] and s[second] == goal[first]