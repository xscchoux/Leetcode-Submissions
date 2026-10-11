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



// Redo
using LL = long long;
class Solution {
public:
    vector<string> res;
    void getCIDR(long long ipAddr, int prefixLen) {
        string ipStr = "";
        for (int i=0; i<4; i++) {
            ipStr = to_string(ipAddr%256) + '.' + ipStr;
            ipAddr /= 256;
        }
        ipStr.pop_back();
        ipStr = ipStr + '/' + to_string(prefixLen);
        res.push_back(ipStr);
    }
    vector<string> ipToCIDR(string ip, int n) {
        long long ipAddr = 0;
        istringstream iss(ip);
        string token;
        while (getline(iss, token, '.')) {
            ipAddr = ipAddr*256 + stoi(token);
        }

        while (n > 0) {
            int lsb = ipAddr&(-ipAddr);  // Least Significant Bit, LSB
            int range;                   // to be used

            if (lsb == 0) {
                // when ip address is zero
                range = log2(n);
            } else {
                range = min(log2(lsb), log2(n));
            }
            getCIDR(ipAddr, 32-range);
            ipAddr += pow(2, range);
            n -= pow(2, range);

        }

        return res;
    }
};