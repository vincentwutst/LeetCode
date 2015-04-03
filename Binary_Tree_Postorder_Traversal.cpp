class Solution{
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> s;
		if (root == NULL) return result;
		
		TreeNode *cur = root;
		TreeNode *pre = NULL;  // track previous popped node
		
		while (!s.empty() || cur)
		{
			if (cur){//一直往左下走，栈顶是左下最后一个，栈底是root
				s.push(cur);
				cur = cur->left;
			}
			else{
				TreeNode *t = s.top();
				// if this node has no right child or its right child has been popped out 
				if (!t->right || t->right == pre){
					result.push_back(t->val);
					s.pop();
					pre = t;
				}
				else cur = t->right;  // push right subtree into stack
			}
		}
		return result;
	}
};
