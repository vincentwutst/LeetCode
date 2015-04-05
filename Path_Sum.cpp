class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL) return false;

		sum -= root->val;
		if (root->left == NULL && root->right == NULL)//题目中要求root-to-leaf path
			return sum == 0;                          //所以要到达leaf时再判断

		return (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
	}
};
