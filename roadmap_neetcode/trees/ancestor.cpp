//Problem: Given  BST and two nodes p and q, determine the lowest common ancestor of these nodes.
//Sol: Whenever I reach a node, if this node's value is between p's and q's values, it is the LCA. Otherwise, keep searching.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int curval = root->val;
        int pval = p->val;
        int qval = q->val;

        if (!root || !p || !q) return nullptr;

        if (min(pval, qval) <= curval && max(pval,qval) >= curval) return root;

        if (max(pval, qval) < curval) return lowestCommonAncestor(root->left, p, q);

        return lowestCommonAncestor(root->right, p, q);            
    }
};
