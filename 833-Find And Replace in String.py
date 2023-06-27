class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        
# First try
        arr = sorted([(idx, src, tg) for idx, src, tg in zip(indices, sources, targets)])
        i = 0
        j = 0
        res = []

        while i < len(s) and j < len(arr):
            if i == arr[j][0]:
                if arr[j][1] == s[i:i+len(arr[j][1])]:
                    res.append(arr[j][2])
                    i += len(arr[j][1])
                else:
                    res.append(s[i])
                    i += 1
                j += 1
            else:
                res.append(s[i])
                i += 1
        
        res.append(s[i:])
        
        return "".join(res)

# Concise solution, go from right to left

        for idx, src, tg in sorted(zip(indices, sources, targets), reverse=True):
            if s[idx:idx+len(src)] == src:
                s = s[:idx] + tg + s[idx+len(src):]
        
        return s