class Solution {
public:
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        istringstream iss(str);
        string token;
        while (getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string> arr1 = split(version1, '.');
        vector<string> arr2 = split(version2, '.');
        int ind1 = 0, ind2 = 0;

        while (ind1 < arr1.size() && ind2 < arr2.size()) {
            int i1 = stoi(arr1[ind1]), i2 = stoi(arr2[ind2]);
            if (i1 < i2) {
                return -1;
            } else if (i1 > i2) {
                return 1;
            }
            ind1++;ind2++;
        }

        while (ind1 < arr1.size()) {
            int i1 = stoi(arr1[ind1]);
            if (i1 > 0) return 1;
            ind1++;
        }

        while (ind2 < arr2.size()) {
            int i2 = stoi(arr2[ind2]);
            if (i2 > 0) return -1;
            ind2++;
        }

        return 0;
    }
};