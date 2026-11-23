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
        return bfs(root);
    }
    TreeNode* bfs(TreeNode* node){
        queue<TreeNode*> q;

        if (!node){
            return nullptr;
        }
        q.push(node);
        
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; ++i){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                std::swap(curr->left, curr->right);
            }
        }
        return node;
    }
};
