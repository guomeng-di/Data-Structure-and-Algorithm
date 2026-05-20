//98. 验证二叉搜索树
//题目分析:
// 要求:
// 节点的左子树只包含 严格小于 当前节点的数。
// 节点的右子树只包含 严格大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

// 即:
// 中序遍历 数字严格递增!
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
    void dfs(TreeNode* node,vector<int>& res){
        if(!node) return;
        dfs(node->left,res);
        res.push_back(node->val);
        dfs(node->right,res);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        dfs(root,res);
        for(int i=0;i<res.size()-1;i++){
            if(res[i]>=res[i+1]) return 0;
        }return 1;
    }
};
