class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        hmap = defaultdict(set)
        
        for u, v in points:
            hmap[v].add(u)
        
        avg = None
        for v in hmap.values():
            arr = sorted(list(v))
            left, right = 0, len(arr) - 1
            
            if avg is None:
                avg = (arr[left] + arr[right])/2
                left += 1
                right -= 1

            while left <= right:
                if (arr[left] + arr[right])/2 != avg:
                    return False
                left += 1
                right -= 1

        return True