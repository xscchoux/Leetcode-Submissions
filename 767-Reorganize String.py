class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        arr = sorted(list(count.keys()), key = lambda x:-count[x])

        if count[arr[0]] > (len(s)+1)//2:
            return ""
        
        N = count[arr[0]]
        bucket = [[] for _ in range(N)]
        idx = 0
        
        for k in arr:
            for _ in range(count[k]):
                bucket[idx%N].append(k)
                idx += 1
        
        return "".join(map(lambda arr:"".join(arr), bucket))