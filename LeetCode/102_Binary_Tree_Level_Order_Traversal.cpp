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
        vector < vector < int > > ans;
        if(root == NULL)    return ans;
        vector < TreeNode* > level[2005];
        
        // { TreeNode, Level }  pair
        queue < pair < TreeNode*, int > > q;
        q.push({ root, 0 });
        level[0].push_back(root);
        int height = 0;
        while(!q.empty()) {
            pair < TreeNode*, int >  tp;
            tp = q.front();
            q.pop();
            if(tp.first == NULL)  continue;
            if(tp.first->left != NULL) {
                q.push({ tp.first->left, tp.second + 1 });
                level[tp.second + 1].push_back(tp.first->left);
                height++;
            }
            if(tp.first->right != NULL) {
                q.push({ tp.first->right, tp.second + 1 });
                level[tp.second + 1].push_back(tp.first->right);
                if(height == tp.second) height++;
            }
        }
        for(int i = 0; i <= height; i++) {
            vector < int > tmp;
            for(auto it:level[i])  tmp.push_back(it->val);
            if(!tmp.empty())       ans.push_back(tmp);
        }
        
        return ans;
        
    }
};