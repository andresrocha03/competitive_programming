//Problem: Given a binary tree, invert it (left childrens become right childrens and vice-versa).
//Solution: Use Recursion to apply DFS and invert tree by swapping nodes' childrens.

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
