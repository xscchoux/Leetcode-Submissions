# Definition for a street.
# class Street:
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
class Solution:
    def houseCount(self, street: Optional['Street'], k: int) -> int:
# Leave the first open door open, and close all doors after that 
# move k steps and save the last open door

        while not street.isDoorOpen():
            street.moveRight()
        
        firstOpen = lastOpen = 0
        street.moveRight()
        move = 1
        
        while move <= k:
            if street.isDoorOpen():
                lastOpen = move
                street.closeDoor()
            street.moveRight()
            move += 1
            
        return lastOpen - firstOpen