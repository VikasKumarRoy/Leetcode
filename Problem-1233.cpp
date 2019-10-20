//Problem - 1233
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

// O(s * nlogn) time complexity and O(n) space complexity sol

class Solution {
public:
    static bool comp(string &a, string &b) {
        return a.length() < b.length();
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        vector <string> ans;
        if(folder.empty())
            return ans;
        sort(folder.begin(), folder.end(), comp);
        unordered_set <string> s;
        for(int i = 0; i < folder.size(); i++) {
            string str;
            int flag = 0;
            for(int j = 0; j < folder[i].length(); j++) {
                str += folder[i][j];
                if((j == folder[i].length()-1 || folder[i][j+1] == '/') && s.find(str) != s.end()) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                    s.insert(str);
                    ans.push_back(str);
                }
        }
        return ans;
    }
};