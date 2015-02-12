class Solution
{
public:
	//判断左子树的结点值是否都小于val 
	bool isSubtreeLessThan(TreeNode *p, int v){
		if (p == NULL) return true;
		return (p->val < v && isSubtreeLessThan(p->left, v) && isSubtreeLessThan(p->right, v));
	}
	
	//判断右子树的结点值是否都大于于val
	bool isSubtreeGreaterThan(TreeNode *p, int v){
		if (p == NULL) return true;
		return (p->val > v && isSubtreeGreaterThan(p->left, v) && isSubtreeGreaterThan(p->right, v));
	}

	//判定二叉树是否是二叉搜索树
	bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;
		return isSubtreeLessThan(root->left, root->val) &&
			isSubtreeGreaterThan(root->right, root->val) &&
			isValidBST(root->left) &&
			isValidBST(root->right);
	}
};
