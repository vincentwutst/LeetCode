class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		TreeNode *p = root;
		stack<TreeNode *> s;
		while (!s.empty() || p != NULL) {
			if (p != NULL) {
				s.push(p);
				p = p->left;//p一直走到左边最后一个结点
			}
			else {
				p = s.top();
				s.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result;
	}
};
