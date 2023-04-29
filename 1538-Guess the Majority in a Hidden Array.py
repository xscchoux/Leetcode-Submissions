# """
# This is the ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#	 # Compares 4 different elements in the array
#	 # return 4 if the values of the 4 elements are the same (0 or 1).
#	 # return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
#	 # return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
#    def query(self, a: int, b: int, c: int, d: int) -> int:
#
#	 # Returns the length of the array
#    def length(self) -> int:
#

class Solution:
    def guessMajority(self, reader: 'ArrayReader') -> int:
# https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/discuss/777014/Python-O(1)-space-with-explanation
        query0123 = reader.query(0, 1, 2, 3)
        query0124 = reader.query(0, 1, 2, 4)
        N = reader.length()
        groupA, groupB = 1, 0
        idxA, idxB = 0, 0
        
        for i in range(4, N):
            if reader.query(0, 1, 2, i) == query0123:
                groupA += 1
                idxA = i
            else:
                groupB += 1
                idxB = i
        
        for i in range(3):
            args = [v for v in [0,1,2,3,4] if v!=i]
            if reader.query(*args) == query0124:
                groupA += 1
                idxA = i
            else:
                groupB += 1
                idxB = i

        if groupA > groupB:
            return idxA
        elif groupB > groupA:
            return idxB
        else:
            return -1