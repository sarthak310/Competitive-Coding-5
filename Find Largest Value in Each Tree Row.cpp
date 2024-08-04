//time: O(n)
//space: O(n)
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        result.push_back(root -> val);
        while(!q.empty()) {
            int sz = q.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left != NULL) {
                    levelMax = max(levelMax, curr->left->val);
                    q.push(curr->left);
                }
                if(curr -> right != NULL) {
                    levelMax = max(levelMax, curr->right->val);
                    q.push(curr->right);
                }
            }
            result.push_back(levelMax);
        }
        result.pop_back();
        return result;
    }
};