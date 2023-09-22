        arr = []
        for i, num in enumerate(nums):
            arr.append((num, i))

        arr.sort(reverse=True) # Note that the second item is also sorted. There is no need to consider numbers with the same values, as the indexes are arranged in descending order, from larger to smaller.
        res = 0
        minIdx = arr[0][1]

        for i in range(1, len(arr)):
            res = max(res, arr[i][1]-minIdx+1)
            minIdx = min(minIdx, arr[i][1])
        
        return res