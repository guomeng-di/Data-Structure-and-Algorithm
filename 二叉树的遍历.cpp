二叉树的三种遍历方式:
1先序遍历(根->左->右)
2中序遍历(左->根->右)
3后序遍历(左->右->根)

dfs实现:
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
class Solution {//中序
private:
    void dfs(TreeNode* node,vector<int>& res){
        if(!node) return;
        dfs(node->left,res);
        res.push_back(node->val);
        dfs(node->right,res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {//中
        vector<int> res;
        dfs(root,res);
        return res;
    }
};
//迭代:
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;//栈实现
        TreeNode* curr=root;

        while(curr||!st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }curr=st.top();//根
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }return res;
    }
};
