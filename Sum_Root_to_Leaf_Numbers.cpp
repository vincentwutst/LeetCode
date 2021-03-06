class Solution {
public:
	int sumNumbers(TreeNode *root) {
		return dfs(root, 0);
	}

	int dfs(TreeNode *root, int sum) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr)
			return sum * 10 + root->val;
		else 
			return dfs(root->left, sum * 10 + root->val)
			+ dfs(root->right, sum * 10 + root->val);
	}
};
