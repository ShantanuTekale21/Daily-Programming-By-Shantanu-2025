#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}
TreeNode* buildTree(vector<int> arr) {
    if (arr.empty()) return nullptr;
    vector<TreeNode*> nodes;
    for (int val : arr) {
        if (val == -1) nodes.push_back(nullptr);
        else nodes.push_back(new TreeNode(val));
    }
    int n = arr.size();
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != nullptr) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}
int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = buildTree(arr);
    if (isSymmetric(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
