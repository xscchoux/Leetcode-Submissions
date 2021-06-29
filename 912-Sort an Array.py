class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
# merge sort
        def mergeSort(arr):
            if len(arr) < 2:
                return arr
            
            mid = len(arr)//2
            leftArr = mergeSort(arr[:mid])
            rightArr = mergeSort(arr[mid:])
            i = j = k = 0
            
            while i<len(leftArr) and j<len(rightArr):
                if leftArr[i] < rightArr[j]:
                    arr[k] = leftArr[i]
                    i+=1
                else:
                    arr[k] = rightArr[j]
                    j+=1
                k+=1
                
            while i<len(leftArr):
                arr[k] = leftArr[i]
                i+=1
                k+=1
                
            while j<len(rightArr):
                arr[k] = rightArr[j]
                j+=1
                k+=1
                
            return arr
        
        return mergeSort(nums)