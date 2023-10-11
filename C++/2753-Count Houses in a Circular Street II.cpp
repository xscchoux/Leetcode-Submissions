/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
public:
// The -> operator is used in C++ to access a member (function or variable) of an object through a pointer. 
// street is a pointer to a Street object, so you need to use the -> operator to call its member functions
    
    int houseCount(Street* street, int k) {
        while (!street->isDoorOpen()){
            street->moveRight();
        }
        street->moveRight();
        int firstOpen = 0, lastOpen = 0;
        for (int step = 1; step <= k; step++){
            if (street->isDoorOpen()){
                street->closeDoor();
                lastOpen = step;
            }
            street->moveRight();
        }
        return lastOpen - firstOpen;
    }
};