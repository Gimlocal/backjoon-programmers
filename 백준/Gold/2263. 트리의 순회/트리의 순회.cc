#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) { }
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* MakeTree(vector<int>& iO, vector<int>& pO, unordered_map<int, int>& iI, int start, int end, int& pI)
{
	if (start > end) return nullptr;

	int val = pO[pI--];
	TreeNode* root = new TreeNode(val);
	
	int iIdx = iI[val];

	root->right = MakeTree(iO, pO, iI, iIdx + 1, end, pI);
	root->left = MakeTree(iO, pO, iI, start, iIdx - 1, pI);

	return root;
}

void PreOrder(TreeNode* root)
{
	if (root == nullptr) return;
	cout << root->value << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

int main()
{
	int n; cin >> n;
	TreeNode* root = nullptr;
	vector<int> inOrder(n); 
	vector<int> postOrder(n); 
	unordered_map<int, int> inOrderIndex;
	for (int i = 0; i < n; i++)
	{
		cin >> inOrder[i];
		inOrderIndex.insert({ inOrder[i], i });
	}
	for (int i = 0; i < n; i++)
	{
		cin >> postOrder[i];
	}

	int pI = n - 1;
	root = MakeTree(inOrder, postOrder, inOrderIndex, 0, n - 1, pI);
	PreOrder(root);
}