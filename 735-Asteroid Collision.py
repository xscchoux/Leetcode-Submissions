class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for s in asteroids:
            if not stack or stack[-1]*s > 0 or (stack[-1] < 0 and s > 0):
                stack.append(s)
            else:
                flag = True
                while stack and stack[-1] > 0:
                    last = stack.pop()
                    if -1*s < last:
                        stack.append(last)
                        flag = False
                        break
                    elif -1*s == last:
                        flag = False
                        break
                if flag:
                    stack.append(s)
                    
        return stack
    
    
# Neater
        stack = []
        for asteroid in asteroids:
            while stack and asteroid < 0 < stack[-1]:
                if -asteroid == stack[-1]:
                    stack.pop()
                elif stack[-1] < -asteroid:
                    stack.pop()
                    continue
                break
            else:
                stack.append(asteroid)
        return stack