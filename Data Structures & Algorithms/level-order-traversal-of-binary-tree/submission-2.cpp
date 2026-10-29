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
        /*
        Time complexity: O(n)
        Space complexity: O(n)
        */
        vector<vector<int>> result;
        queue<TreeNode*> queue;

        if(root){
            queue.push(root);
        }

        int level = 0;
        while (queue.size() > 0){
            int length = queue.size();
            vector<int> group{};
            for (int i = 0; i < length; ++i){
                TreeNode* curr = queue.front();
                group.push_back(curr -> val);
                queue.pop();
                if (curr -> left){
                    queue.push(curr -> left);
                }
                if (curr -> right){
                    queue.push(curr -> right);
                }
            }
            result.push_back(group);
            while(group.size() > 0){
                group.pop_back();
            }
            level++;
        }
        return result;
    }
};
