class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode *> s;
		TreeNode *p;

		p = root;
		if (p != NULL) s.push(p);

		while (!s.empty())
		{
			p = s.top();
			s.pop();
			result.push_back(p->val); // 访问根节点 
			if (p->right != NULL) s.push(p->right);  // 访问右结点
			if (p->left != NULL)  s.push(p->left);  // 访问左结点

		}
		return result;
	}
};
