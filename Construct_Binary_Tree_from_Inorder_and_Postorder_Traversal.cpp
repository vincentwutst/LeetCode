class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (postorder.size() != inorder.size()) return NULL;
		int n = postorder.size();
		return buildBT(postorder, inorder, 0, n - 1, 0, n - 1);
	}

	TreeNode *buildBT(vector<int> &postorder, vector<int> &inorder, int s1, int e1, int s2, int e2) {
		//s1,e1:后序排列中的始末点   s2,e2:中序排列中的始末点
		if (s1>e1 || s2>e2) return NULL;
		TreeNode *root = new TreeNode(postorder[e1]);//找到root，后序的最后一个值

		int rootIndex = -1; // 记录root结点在中序中的位置
		for (int i = s2; i <= e2; i++) {
			if (inorder[i] == root->val) {
				rootIndex = i;
			}
		}
		if (rootIndex == -1) return NULL;
		int leftTreeSize = rootIndex - s2;//左子树的size
		int rightTreeSize = e2 - rootIndex;//右子树的size

		root->left = buildBT(postorder, inorder, s1, s1 + leftTreeSize - 1, s2, rootIndex - 1);
		root->right = buildBT(postorder, inorder, e1 - rightTreeSize, e1 - 1, rootIndex + 1, e2);
		return root;
	}
};
