class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        
# Top-down, O(mnlogn)
        arr2.sort()
        
        @cache
        def dfs(idx, prev):
            if idx == len(arr1):
                return 0
            
            res = float('inf')
            if arr1[idx] > prev:
                res = min(res, dfs(idx+1, arr1[idx]))
                
            pick = bisect_right(arr2, prev)
            if pick != len(arr2):
                res = min(res, 1 + dfs(idx+1, arr2[pick]))
                
            return res

        ans = dfs(0, -1)
        
        return ans if ans < float('inf') else -1
        
# bottom-up, O(mnlogn)
# https://blog.csdn.net/guojunxiu/article/details/100690197
        arr2.sort()
        prevDict = {-1:0} # previous number: previous operation
        
        for i in range(len(arr1)):
            tmp = defaultdict(lambda:float('inf'))
            for prev in prevDict:
                if arr1[i] > prev:
                    tmp[arr1[i]] = min(tmp[arr1[i]], prevDict[prev])
                # use a number in arr2
                idx = bisect_right(arr2, prev)
                if idx != len(arr2):
                    tmp[arr2[idx]] = min(tmp[arr2[idx]], prevDict[prev] + 1)
            prevDict = tmp
            
        if not prevDict:
            return -1
        return min(prevDict.values())