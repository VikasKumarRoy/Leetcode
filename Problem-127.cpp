//Problem - 127
// https://leetcode.com/problems/word-ladder/

// O(n * n * m) solution

class Solution {
public:
    int diff(string s, string t) {
        int ctr = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i])
                ctr++;
        }
        return ctr;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector <int> adj[wordList.size()];
        
        for(int i = 0; i < wordList.size()-1; i++)
            for(int j = i+1; j < wordList.size(); j++) {
                if(diff(wordList[i], wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        
        queue <int> q;
        for(int i = 0; i < wordList.size(); i++) {
            if(diff(wordList[i], beginWord) == 1)
                q.push(i);
        }
        int ctr = 1;
        vector <int> visited(wordList.size(), 0);
        while(!q.empty()) {
            int size = q.size();
            ctr++;
            while(size--) {
                int u = q.front();
                q.pop();
                visited[u] = 1;
                if(wordList[u] == endWord)
                    return ctr;
                for(auto itr = adj[u].begin(); itr != adj[u].end(); itr++)
                    if(!visited[*itr])
                        q.push(*itr);
            }
   
        }
        return 0;
    }
};
   