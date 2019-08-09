//Problem  - 394
// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decoder(string s, int &i) {
        string ans;
        int ctr = 0;
        while(i < s.length()) {
            if(isdigit(s[i])) {
                ctr = ctr*10 + (s[i++] - '0');
            }
            else if(s[i] == '[') {
                i++;
                string a = decoder(s, i);
                for(int j = 0; j < ctr; j++)
                    ans += a;
                ctr = 0;
            }
            else if(s[i] == ']') {
                i++;
                return ans;
            }
            else {
                ans += s[i++];
            }
        }
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decoder(s, i);
    }
};