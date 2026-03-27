//99. 恢复二叉搜索树
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
    void dfs(TreeNode* node,vector<TreeNode*>& res){
        if(!node) return;
        dfs(node->left,res);
        res.push_back(node);
        dfs(node->right,res);
    }
public:
    void recoverTree(TreeNode* root) {
        //中序遍历
        vector<TreeNode*> res;
        dfs(root,res);
        TreeNode* x=nullptr;
        TreeNode* y=nullptr;
        for(int i=0;i<res.size()-1;i++){
            if(res[i]->val>res[i+1]->val){//两个节点可能不相邻
                if(x==nullptr) x=res[i];
                y=res[i+1];
                
            }
        }swap(x->val,y->val);
        }
};