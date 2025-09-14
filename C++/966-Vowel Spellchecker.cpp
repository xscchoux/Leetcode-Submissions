// Use regex and regex_replace(), slower
// std::regex in C++ is convenient, but it's very slow because it involves compiling the regex pattern and running a full matching engine. 
// Even for a simple pattern like [aeiou], the overhead is significant.
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s;
        unordered_map<string, string> hmap;
        unordered_map<string, string> hmap2; // vowel error
        regex r("[aeiou]");
        for (auto &w:wordlist) {
            s.insert(w);
            string curr = w;
            for (auto &c:curr) {
                c = tolower(c);
            }
            if (!hmap.count(curr)) hmap[curr] = w;
            string replaced = regex_replace(curr, r, "_");
            if (!hmap2.count(replaced)) {
                hmap2[replaced] = w;
            }
        }

        for (auto &q:queries) {
            if (s.count(q)) {
                continue;
            } 
            for (auto &c:q) {
                c = tolower(c);
            }
            if (hmap.count(q)) {
                q = hmap[q];
                continue;
            }
            string replaced = regex_replace(q, r, "_");
            if (hmap2.count(replaced)) {
                q = hmap2[replaced];
            } else {
                q = "";
            }   
        }
        return queries;
    }
};


// Without using regex
class Solution {
public:
    string replaceVowel(string s) {
        for (char& c:s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '_';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s;
        unordered_map<string, string> hmap;
        unordered_map<string, string> hmap2; // vowel error

        for (auto &w:wordlist) {
            s.insert(w);
            string curr = w;

            for (auto &c:curr) {
                c = tolower(c);
            }
            if (!hmap.count(curr)) hmap[curr] = w;
            string replaced = replaceVowel(curr);
            if (!hmap2.count(replaced)) {
                hmap2[replaced] = w;
            }
        }


        for (auto &q:queries) {

            if (s.count(q)) {
                continue;
            } 

            for (auto &c:q) {
                c = tolower(c);
            }
            if (hmap.count(q)) {
                q = hmap[q];
                continue;
            }

            string replaced = replaceVowel(q);
            if (hmap2.count(replaced)) {
                q = hmap2[replaced];
            } else {
                q = "";
            }   
        }

        return queries;
    }
};