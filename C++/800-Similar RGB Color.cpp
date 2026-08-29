class Solution {
public:
    string similarRGB(string color) {
        vector<int> arr;
        for (int i=0; i<=16; i++) {
            arr.push_back(i*16 + i);
        }

        string res = "#";
        for (int i=1; i<color.size(); i+=2) {
            // int n1 = isalpha(color[i])?(color[i]-'a'+10):(color[i]-'0');
            // int n2 = isalpha(color[i+1])?(color[i+1]-'a'+10):(color[i+1]-'0');

            // int num = n1*16 + n2;

            int num = stoi(color.substr(i, 2), nullptr, 16);

            int diff = INT_MAX, idx = -1;
            for (int j=0; j<arr.size(); j++) {
                int d = abs(num-arr[j]);
                if (d < diff) {
                    diff = d;
                    idx = j;
                }
            }

            if (idx < 10) {
                res += string(2, idx + '0');
            } else {
                res += string(2, 'a' + (idx-10));
            }

        }

        return res;
    }
};