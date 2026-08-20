//Problem: create a copy of a linked list in which each node points to the next one in the list and may point to a random one
//Sol: Use a hash map to store the new nodes and them traverse list using map to translate old links to new ones.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> new_nodes;

        Node* node = head;
        while (node) {
            new_nodes[node] = new Node(node->val); 
            node = node->next;
        } 
        new_nodes[nullptr] = nullptr;

        node = head;
        while (node) {
            new_nodes[node]->next = new_nodes[node->next];
            new_nodes[node]->random = new_nodes[node->random];
            node = node->next;
        }

        return new_nodes[head];
    }
};
