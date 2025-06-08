#include <iostream>
using namespace std;

struct TreeNode
{
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) { }
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* insert(TreeNode* root, int val)
{
	if (root == nullptr) return new TreeNode(val);
	if (val < root->value) root->left = insert(root->left, val);
	else root->right = insert(root->right, val);
	return root;
}

void PostOrder(TreeNode* root)
{
	if (root == nullptr) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->value << "\n";
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	int val;
	TreeNode* root = nullptr;
	while (cin >> val) root = insert(root, val);
	PostOrder(root);
}