class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) 
	{
		vector<vector<int> > result;
		vector<int> level;//elements in level

		if (root == NULL)
			return result;

		queue<TreeNode *> current, next;//创建两个queue保存当前层的结点和下一层的结点
		current.push(root);
		
		while (!current.empty())
		{
			while (!current.empty())
			{
				TreeNode * p = current.front();
				current.pop();
				level.push_back(p->val);
				if (p->left != NULL)  next.push(p->left);
				if (p->right != NULL) next.push(p->right);
			}
			result.push_back(level);
			level.clear();
			//swap current and next
			queue<TreeNode *> temp = current;
			current = next;
			next = temp;
		  //swap(next, current);
		}
		return result;
	}
};
