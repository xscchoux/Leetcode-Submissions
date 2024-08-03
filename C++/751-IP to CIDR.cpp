using LL = long long;
class Solution {
public:
    string getCIDR(LL num, int prefix) {
        string IP = "";
        int group = 4;
        while (group-- > 0) {
            IP = to_string(num%256) + "." + IP;
            num = num/256;
        }
        IP.pop_back();

        return IP + '/' + to_string(prefix);
    }

    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;

        LL ipNum = 0;
        stringstream iss(ip);
        string token;
        while (getline(iss, token, '.')) {
            ipNum = ipNum*256 + stoi(token);
        }        

        while (n > 0) {
            int bit = ipNum&(-ipNum);
            int range;

            if (bit == 0) range = (int)log2(n);   // No log2(0) !!
            else range = min((int)log2(bit), (int)log2(n));
            
            string curr = getCIDR(ipNum, 32-range);
            res.push_back(curr);
            ipNum += pow(2, range);
            n -= pow(2, range);
        }

        return res;
    }
};