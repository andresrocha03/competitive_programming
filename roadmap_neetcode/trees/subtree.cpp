//Problem: Given 2 trees t1 and t2, find out if there is any subtree of t1 that is equivalent to t2
//Sol: Use dfs to traverse and check for each node verify if it is subtree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        else if (!root) return false;
        
        bool match = sameTree(root, subRoot);          
        bool ml = isSubtree(root->left, subRoot);
        bool mr = isSubtree(root->right, subRoot);

        return match || ml || mr;
    }

private:
    bool sameTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }
        else if (t1 && t2) {
            return (t1->val == t2->val) && sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);
        } 

        return false;
    }
};
