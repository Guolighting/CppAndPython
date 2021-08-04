/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    unordered_map<TreeNode*,TreeNode*>node_parent;
    //建邻接表
    void dfs_find_node_parent(TreeNode *node){
        if(node){
            if(node->left){
                node_parent[node->left]=node;
            }
            if(node->right){
                node_parent[node->right]=node;
            }
            dfs_find_node_parent(node->left);
            dfs_find_node_parent(node->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs_find_node_parent(root);
        //距离为0,别忘了
        if(k==0)
        {
            return vector<int>{target->val};
        }
        vector<int>res;
        queue<TreeNode*>Q;
        unordered_set<TreeNode*>visited;
        Q.push(target);
        visited.insert(target);
        int level=0;
        while(!Q.empty()&&level<k){
            level++;
            int cur_len=(int)Q.size();
            for(int i=0;i<cur_len;i++){
                TreeNode* x=Q.front();
                Q.pop();
                if(node_parent[x]&&visited.find(node_parent[x])==visited.end()){
                    if(level==k){
                        res.push_back(node_parent[x]->val);
                    }
                    visited.insert(node_parent[x]);
                    Q.push(node_parent[x]);          
                }
                if(x->left&&visited.find(x->left)==visited.end()){
                    if(level==k){
                        res.push_back(x->left->val);
                    }
                    visited.insert(x->left);
                    Q.push(x->left);
                }
                if(x->right&&visited.find(x->right)==visited.end()){
                    if(level==k){
                        res.push_back(x->right->val);
                    }
                    visited.insert(x->right);
                    Q.push(x->right);
                }
            }
        }
    return res;
    }
    /*
    1109
    957
    499
    582
    1239
    210
    315

    BFS:
    127
    139
    130
    317
    505
    529
    1263
    1197
    815
    934
    DFS:
    934
    1102
    685
    '531
    533
    332
    337
    113
    
    */
};