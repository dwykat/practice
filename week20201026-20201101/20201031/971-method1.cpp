/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int index = 0;
    vector<int> result;

    bool dfs(TreeNode* root, vector<int>& voyage){
        if(root == nullptr)
            return true;
        if(index >= voyage.size())
            return false;

        if(root->val != voyage[index])
            return false;
            
        index++;
        if(root->left != nullptr && index < voyage.size() && root->left->val != voyage[index]){
            // 不等于，就交换
            result.push_back(root->val); // 该父节点需要保存

            // 交换后的先序遍历，先右后左
            return dfs(root->right, voyage) && dfs(root->left, voyage);
        }else{
            // 匹配成功，按先序继续遍历
            return dfs(root->left, voyage) && dfs(root->right, voyage);
        }
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(dfs(root, voyage))
            return result;
        return {-1};
    }
};
