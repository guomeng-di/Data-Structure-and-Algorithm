//https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //1正常层序遍历
        vector<vector<int>> arr;
        if(root==nullptr) return arr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentLevelSize=q.size();
            arr.push_back(vector<int>());
            for(int i=0;i<currentLevelSize;i++){
                TreeNode* node=q.front();
                q.pop();
                arr.back().push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
             }

        }

        //2调换顺序
        for(int i=1;i<arr.size();i+=2){
            reverse(arr[i].begin(),arr[i].end());
        }

        return arr;
    }
};
