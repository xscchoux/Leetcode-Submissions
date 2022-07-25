class Solution:
    def visibleMountains(self, peaks: List[List[int]]) -> int:
        span = []
        count = collections.Counter([(u-v, u+v) for u, v in peaks])
        for k, v in count.items():
            if v == 1:        # do not append "duplicate" spans
                span.append(k)
                
        span.sort(key = lambda x:(x[0], -x[1]))
        res = len(peaks)
        
        stack = []
        for s, e in span:
            covered = False
            if stack and e <= stack[-1][1]:
                covered = True
                
            if not covered:
                stack.append((s, e))
        return len(stack)