//Problem:  Given a binary tree, return the level order traversal of it
//Sol: Use BFS


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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> visited;
        if (!root) return visited;

        queue<pair<TreeNode*, int>> todo;
        
        vector<int> level_nodes;
        TreeNode* curr_node;
        int curr_level = 0;
        todo.push({root, 0});

        while (!todo.empty()) {
            curr_node = todo.front().first;
            if (curr_level < todo.front().second) {
                visited.push_back(level_nodes);
                level_nodes.clear();
                curr_level = todo.front().second;
            };
            level_nodes.push_back(curr_node->val);
            todo.pop();
            if (curr_node->left) todo.push({curr_node->left,curr_level+1});
            if (curr_node->right) todo.push({curr_node->right,curr_level+1});
        }
        
        visited.push_back(level_nodes);
        return visited;
    }
};
