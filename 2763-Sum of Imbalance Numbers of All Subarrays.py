class Solution:
    def sumImbalanceNumbers(self, nums: List[int]) -> int:
        N = len(nums)
        res = 0
        
        for i in range(N):
            visited = set([nums[i]])
            curr = 0
            for j in range(i+1, N):
                if nums[j] in visited:
                    res += curr
                elif nums[j] - 1 in visited and nums[j] + 1 in visited:
                    curr -= 1
                    res += curr
                elif nums[j] - 1 not in visited and nums[j] + 1 not in visited:
                    curr += 1
                    res += curr
                else:
                    res += curr
                visited.add(nums[j])
            
        return res


# Same as above
        N = len(nums)
        res = 0
        
        for i in range(N):
            visited = set([nums[i]])
            curr = 0
            for j in range(i+1, N):
                if nums[j] not in visited:
                    curr += 1
                    if nums[j] + 1 in visited:
                        curr -= 1
                    if nums[j] - 1 in visited:
                        curr -= 1
                res += curr
                visited.add(nums[j])
            
        return res
                    
# Count subarrays by element, very clever and hard O(n) solution
# left[i] gives the closest index of nums[i] + 1 or nums[i]
# right[i] gives the closest index of nums[i] + 1
# remove N*(N-1)//2 because in all N*(N-1)//2 subarrays the biggest number contribute one to the answer

        N = len(nums)
        res = 0
        left, right = [-1]*N, [N]*N
        
        leftMap = dict()
        for i in range(N):
            if nums[i] in leftMap:
                left[i] = leftMap.get(nums[i])
            if nums[i] + 1 in leftMap:
                left[i] = max(left[i], leftMap.get(nums[i]+1))
            leftMap[nums[i]] = i
            
        rightMap = dict()
        for i in range(N-1, -1, -1):
            if nums[i] + 1 in rightMap:
                right[i] = rightMap.get(nums[i]+1)
            rightMap[nums[i]] = i
        
        for i in range(N):
            res += (i - left[i])*(right[i] - i)
            
        return res - N*(N+1)//2