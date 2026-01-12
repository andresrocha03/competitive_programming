//Problem: enconde a list of strings to a single string and then decode it back to the original list of strings
//Sol: encode the list with its length at the beggining and "*" as an identifier that the string is starting

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (auto str: strs) {
            int length = str.size();   
            encoded += to_string(length) + "*" + str ;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        
        int i = 0;
        while (i < s.size()) { 
            int exp = 0;
            int length = 0;
            while (s[i] != '*') {
                length = length*pow(10,exp);
                length += (s[i] - '0'); 
                i++;                
                exp++;
            }
            string sub = s.substr(i+1, length);
            strs.push_back(sub);
            i += length + 1; 
        }

        return strs;
    }

};
