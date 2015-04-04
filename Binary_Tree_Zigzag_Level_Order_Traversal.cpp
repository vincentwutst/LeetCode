class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > result;
		vector<int> level; // one level's elements
		if (root == NULL) return result;
	
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL); // level separator

		bool left_to_right = true; //left to right

		while (!q.empty()) {
			TreeNode *cur = q.front();
			q.pop();
			if (cur) {
				level.push_back(cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			else {
				if (left_to_right) {
					result.push_back(level);
				}
				else {
					reverse(level.begin(), level.end());
					result.push_back(level);
				}
				level.clear();
				left_to_right = !left_to_right;
				if (q.size() > 0) q.push(NULL);
			}
		}
		return result;
	}
};
