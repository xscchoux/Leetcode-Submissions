class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int res = 0;
        int right = people.size()-1, left = 0;

        while (right >= left) {
            if (right > left && people[right] + people[left] <= limit) {
                left++;
            }
            right--;
            res++;
        }

        return res;
    }
};