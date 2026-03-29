//102. 二叉树的层序遍历
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
private:
    queue<TreeNode*> q;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();//当前层有几个节点
            vector<int> curr;
            for(int i=0;i<cnt;i++){
            TreeNode* node=q.front();
            q.pop();
            curr.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};