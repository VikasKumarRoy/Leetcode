// Problem - 208

// https://leetcode.com/problems/implement-trie-prefix-tree/

// Search- O(m) time complexity and O(1) space complexity or O(mlogn) time if balanced
// Insert- O(m) time complexity and O(m) space complexity where m is the key length

struct Node {
    Node *children[26];
    bool eow;
    Node() {
        eow = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node *root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(curr->children[word[i]-'a'] != NULL)
                curr = curr->children[word[i]-'a'];
            else {
                Node *newNode = new Node();
                curr->children[word[i]-'a'] = newNode;
                curr = newNode;
            }                
        }
        curr->eow = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(!curr->children[word[i]-'a'])
                return false;
            curr = curr->children[word[i]-'a'];
        }
        return curr->eow;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(!curr->children[prefix[i]-'a'])
                return false;
            curr = curr->children[prefix[i]-'a'];
        }
        return true;
    }
};
