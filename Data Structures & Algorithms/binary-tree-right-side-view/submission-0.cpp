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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> queue;

        if (root){
            queue.push(root);
        }
        
        int level = 0;
        while (!queue.empty()){
            int length = queue.size();
            for (int i = 0; i < length; ++i){
                TreeNode* curr = queue.front();
                if (level == 0){
                    result.push_back(curr -> val);
                    ++level;
                }
                queue.pop();
                if (curr -> right){
                    queue.push(curr -> right);
                }
                if(curr -> left){
                    queue.push(curr -> left);
                }
            }
            level = 0;
        }
        return result;
    }
};
