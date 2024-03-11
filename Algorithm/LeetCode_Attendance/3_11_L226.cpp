#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }

    void preOrderRecur(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        cout << head->val << ",";
        preOrderRecur(head->left);
        preOrderRecur(head->right);
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root ->left = new TreeNode(2);
    root ->right = new TreeNode(7);
    root ->left->left = new TreeNode(1);
    root ->left->right = new TreeNode(3);
    root ->right->left = new TreeNode(6);
    root ->right->right = new TreeNode(9);
    Solution s;
    TreeNode * newRoot = s.invertTree(root);
    s.preOrderRecur(newRoot);
    return 0;
}