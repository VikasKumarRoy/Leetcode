// Problem - 211

// https://leetcode.com/problems/add-and-search-word-data-structure-design/

// O(n) time complexity for addWord and O(m) time for search where m is total no. of chars
// O(m) space complexity solution using trie and dfs

struct Node {
    Node *children[26];
    bool eow;
    Node() {
        eow = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *root;
    
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *curr = root;
        for(char c : word) {
            if(!curr->children[c-'a']) {
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->eow = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool dfs(string word, Node *root, int pos) {
        if(pos == word.length())
            return root->eow;
        if(word[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if(root->children[i]) {
                    if(dfs(word, root->children[i], pos+1))
                        return true;
                }
            }
        }
        else {
            if(!root->children[word[pos]-'a'])
                return false;
            else
                return dfs(word, root->children[word[pos]-'a'], pos+1);
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }
};
