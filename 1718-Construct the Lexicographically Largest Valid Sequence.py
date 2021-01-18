class Solution(object):
    def constructDistancedSequence(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        used = set()
        length = 2*n-1
        res = [0]*length
        
        def backtrack(index):
            if index == length:
                return True
            if res[index] != 0:
                return backtrack(index+1)
            else:
                for num in range(n, 0, -1):
                    if num == 1 and num not in used:
                        res[index] = num
                        used.add(num)
                        if backtrack(index+1):
                            return True
                        used.remove(num)
                        res[index] = 0
                    elif num != 1 and num not in used and index+num < length and res[index+num] == 0:
                        res[index] = res[index+num] = num
                        used.add(num)
                        if backtrack(index+1):
                            return True
                        used.remove(num)
                        res[index] = res[index+num] = 0
            return False
        
        backtrack(0)
        return res