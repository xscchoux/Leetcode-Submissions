class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        N = len(positions)
        arr = sorted([(pos, h, d, i) for i, (pos, h, d) in enumerate(zip(positions, healths, directions))])
        
        stack = []
        for i in range(len(arr)):
            if arr[i][2] == 'R':
                stack.append(arr[i])
            else:
                pos, h, d, i = arr[i]
                remove = False
                while stack and stack[-1][2] == "R":
                    prevPos, prevH, prevD, prevIdx = stack.pop()
                    if h < prevH:
                        pos, h, d, i = prevPos, prevH-1, prevD, prevIdx
                        break
                    elif h > prevH:
                        h -= 1
                    else:
                        remove = True
                        break
                if not remove:
                    stack.append((pos, h, d, i))
        
        stack.sort(key = lambda x: x[3])
        
        return [s[1] for s in stack]