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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root)[1];
    }
    vector<int> dfs(TreeNode* node){
        if (!node){
            return {0, diameter};
        }

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        diameter = max(diameter, left[0] + right[0]);
        int height = 1 + max(left[0], right[0]);

        return {height, diameter};
    }
};
