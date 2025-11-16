// Copied code from Geeksforgeeks
// https://www.geeksforgeeks.org/dsa/count-numbers-having-0-as-a-digit/
class Solution {
public:
    long long zeroUpto(long long digits)
    {
        // Refer below article for details
        // https://www.geeksforgeeks.org/dsa/count-positive-integers-0-digit/
        long long first = (pow(10,digits)-1LL)/9;
        long long second = (pow(9,digits)-1LL)/8;
        return 9 * (first - second);
    }

    // utility function to convert character representation
    // to integer
    long long toInt(char c)
    {
        return (long long)int(c)-48;
    }

    // counts numbers having zero as digits upto a given
    // number 'num'
    long long countZero(string num)
    {
        // k denoted the number of digits in the number
        long long k = num.length();

        // Calculating the total number having zeros,
        // which upto k-1 digits
        long long total = zeroUpto(k-1);

        // Now let us calculate the numbers which don't have
        // any zeros. In that k digits upto the given number
        long long non_zero = 0;
        for (int i=0; i<num.length(); i++)
        {
            // If the number itself contains a zero then
            // decrement the counter
            if (num[i] == '0')
            {
                non_zero--;
                break;
            }

            // Adding the number of non zero numbers that
            // can be formed
            non_zero += (toInt(num[i])-1) * (pow(9,k-1-i));
        }

        long long no = 0, remaining = 0,calculatedUpto=0;

        // Calculate the number and the remaining after
        // ignoring the most significant digit
        for (int i=0; i<num.length(); i++)
        {
            no = no*10 + (toInt(num[i]));
            if (i != 0)
                calculatedUpto = calculatedUpto*10 + 9;
        }
        remaining = no-calculatedUpto;

        // Final answer is calculated
        // It is calculated by subtracting 9....9 (d-1) times
        // from no.
        // minus 1 if `num` itself does not contain 0
        long long ans = zeroUpto(k-1) + (remaining-non_zero-1);
        return ans;
    }
    long long countDistinct(long long n) {
        string s = to_string(n);

        long long hasZeroCnt = countZero(s);

        return n - hasZeroCnt;
    }
};




class Solution {
public:
    long long countDistinct(long long n) {
        // find the number of integers that do not contain zero

        // Dont' use log10(n) here because it fails when n is large
        int length = to_string(n).size();
        vector<long long> powOfNine(length, 0);
        powOfNine[0] = 1;
        long long res = 0;

        // count the numbers of size < length and without 0
        for (int i=1; i<length; i++) {
            powOfNine[i] = powOfNine[i-1]*9;
            res += powOfNine[i];
        }

        // count the numbers of size == length and without 0
        string s = to_string(n);
        for (int i=0; i<length; i++) {
            if (s[i] == '0') return res;
            res += (long long)((s[i]-'0')-1)*powOfNine[length-1-i];
        }

        return res+1;  // add one if n itself doesn't contain 0
    }
};