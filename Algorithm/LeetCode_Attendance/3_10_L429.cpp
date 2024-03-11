#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; ++ i) {
                Node * cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (Node* child: cur->children) {
                    q.push(child);
                }
            }

            ans.push_back(move(level));
        }

        return ans;
    }
};

//int main() {
//    Node *root = new Node(1);
//    root -> children.push_back(new Node(3));
//    root -> children.push_back(new Node(2));
//    root -> children.push_back(new Node(4));
//
//    Node * rootChild = root->children[0];
//    rootChild -> children.push_back(new Node(5));
//    rootChild -> children.push_back(new Node(6));
//
//    Solution s;
//    vector<vector<int>> ans = s.levelOrder(root);
//    for (auto v: ans) {
//        for (auto i: v) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}