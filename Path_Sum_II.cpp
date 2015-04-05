class Solution {
	public:
	    vector<vector<int> > pathSum(TreeNode *root, int sum) {
			vector<vector<int> > result;
			vector<int> path;
			if (root == NULL) return result;
			DFS(root, sum, 0, path, result);
			return result;
		}

		void DFS(TreeNode *root, int sum, int start, vector<int> &path, vector<vector<int> > &result) {
			if (root == NULL) return;
			start += root->val;	
			path.push_back(root->val);

			if (root->left == NULL && root->right == NULL) {
				if (start == sum) 
				    result.push_back(path);
			}
			                                                
			DFS(root->left, sum, start, path, result);
			DFS(root->right, sum, start, path, result);

			path.pop_back();
		}
	};
