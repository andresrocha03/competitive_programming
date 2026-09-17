//Problem: Implement a Word dictionary in which it is possible to insert and search words. A searched word can have at most 2 '.'. The '.' can be any character.
//Sol: Use a trie to store the words. When searching,  if encounter a '.', traverse all child of current node and do dfs from each one of them.

class Node {
public:
    unordered_map<char, Node*> children;
    bool eow = false;
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (auto c : word) {
            if (cur->children.count(c)==0) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->eow=true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, Node* node) {
        Node* cur = node;
        for (int i=j;i<word.size();i++) {
            char x = word[i];

            if (x=='.') {
                for (auto child : cur->children) {
                    if (dfs(word, i+1, child.second)) return true;
                }
                return false;
            }
            else {
                if (cur->children.count(x)==0) return false;
                cur = cur->children[x];
            }
        }
        return cur->eow;
    }
};
