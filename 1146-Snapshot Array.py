class SnapshotArray:

    def __init__(self, length: int):
        self.hmap = defaultdict(lambda:[(0, 0)])  # [(snapID1, value1), (snapID2, value2), ...]
        self.snapID = 0

    def set(self, index: int, val: int) -> None:
        self.hmap[index].append((self.snapID, val))

    def snap(self) -> int:
        self.snapID += 1
        return self.snapID - 1

    def get(self, index: int, snap_id: int) -> int:
        arr = self.hmap[index]

        left, right = 0, len(arr) - 1

        while left + 1 < right:
            mid = left + (right-left)//2
            if arr[mid][0] <= snap_id:
                left = mid
            else:
                right = mid

        if arr[right][0] <= snap_id:
            return arr[right][1]
        else:
            return arr[left][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)