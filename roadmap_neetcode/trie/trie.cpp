//Problem: Implement a trie
//Sol: Use a tree structure where each node has 26 children (for each letter of the alphabet) and a flag to know if we reached the end of the word.

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool eow = false;
};


class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (auto c:word) {
            if (curr->children.count(c)==0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (auto c:word) {
            if (curr->children.count(c)==0) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto c:prefix) {
            if (curr->children.count(c)==0) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
