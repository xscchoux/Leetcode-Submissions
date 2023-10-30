class Solution {
static bool compare(int a, int b){
    int bit_a = 0, bit_b = 0;
    int tmp_a = a, tmp_b = b;
    while (a > 0){  // count set bits
        a = a&(a-1);
        bit_a++;
    }
    while (b > 0){
        b = b&(b-1);
        bit_b++;
    }
    return (bit_a != bit_b)?(bit_a < bit_b):(tmp_a<tmp_b);
}
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};