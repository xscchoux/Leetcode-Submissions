class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count = collections.Counter(nums)
        unique = list(count.keys())
        n = len(unique)
        
        def partition(left, right):
            i = left-1
            for j in range(left, right):
                if count[unique[j]] > count[unique[right]]:
                    i+=1
                    unique[i], unique[j] = unique[j], unique[i]

            unique[i+1], unique[right] = unique[right], unique[i+1]
            return i+1

        def main(start, end):
            pivotIdx = partition(start, end)
            if pivotIdx == k-1:
                return pivotIdx
            elif pivotIdx < k-1:
                return main(pivotIdx+1, end)
            else:
                return main(start, pivotIdx-1)

        idx = main(0, len(unique)-1)
        
        return unique[:k]