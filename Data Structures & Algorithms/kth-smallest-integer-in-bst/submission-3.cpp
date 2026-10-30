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
    int count = 0;
    int result = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }

private:
    void inorder(TreeNode* node, int k) {
        if (!node || count >= k) return;

        // Subárbol izquierdo
        inorder(node->left, k);

        // Nodo actual
        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        // Subárbol derecho
        inorder(node->right, k);
    }
};