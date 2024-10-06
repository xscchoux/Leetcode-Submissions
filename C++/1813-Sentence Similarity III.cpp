class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        string word;
        vector<string> arr1, arr2;
        stringstream ss1(s1), ss2(s2);
        while (ss1 >> word) arr1.push_back(word);
        while (ss2 >> word) arr2.push_back(word);

        if (arr1.size() > arr2.size()) swap(arr1, arr2);

        int start1 = 0, end1 = arr1.size()-1, end2 = arr2.size()-1;

        while (start1<arr1.size() && arr1[start1] == arr2[start1]) start1++;
        while (end1>=0 && arr1[end1] == arr2[end2]) {
            end1--;
            end2--;
        }

        return start1 > end1;
    }
};