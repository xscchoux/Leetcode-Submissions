class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        deque<string> dq;
        int digit = 0;

        unordered_map<int, string> intToWord = {
            {1, "One"},       {2, "Two"},        {3, "Three"},
            {4, "Four"},      {5, "Five"},       {6, "Six"},
            {7, "Seven"},     {8, "Eight"},      {9, "Nine"},
            {10, "Ten"},      {11, "Eleven"},    {12, "Twelve"},
            {13, "Thirteen"}, {14, "Fourteen"},  {15, "Fifteen"},
            {16, "Sixteen"},  {17, "Seventeen"}, {18, "Eighteen"},
            {19, "Nineteen"}, {20, "Twenty"},    {30, "Thirty"},
            {40, "Forty"},    {50, "Fifty"},     {60, "Sixty"},
            {70, "Seventy"},  {80, "Eighty"},    {90, "Ninety"}
        };

        unordered_map<int, string> digitToWord = {
            {3, "Thousand"}, {6, "Million"}, {9, "Billion"}
        };

        while (num > 0) {
            auto [thousand, hundreds] = div(num, 1000);
            auto [hundred, tens] = div(hundreds, 100);

            if (digit > 0 && hundreds != 0) {
                dq.push_front(digitToWord[digit]);
            }
            digit += 3;

            if (tens >= 20) {
                if (tens % 10)
                    dq.push_front(intToWord[tens % 10]);
                dq.push_front(intToWord[10 * (tens / 10)]);

            } else if (tens > 0) {
                dq.push_front(intToWord[tens]);
            }

            if (hundred > 0) {
                dq.push_front("Hundred");
                dq.push_front(intToWord[hundred]);
            }
            num = thousand;
        }

        string res = "";
        while (!dq.empty()) {
            res += dq.front() + " ";
            dq.pop_front();
        }

        res.pop_back();
        return res;
    }
};