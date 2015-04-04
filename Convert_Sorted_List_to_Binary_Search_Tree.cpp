class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		int len = 0;
		ListNode *p = head;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}//找出list的长度len
		return generate(head, len);
	}

	TreeNode* generate(ListNode* head, int len) {
		if (len == 0) return NULL;
		if (len == 1) return new TreeNode(head->val);

		int mid = (1 + len) / 2;
		int tmp = mid - 1;
		ListNode *p = head;
		while (tmp > 0)
		{
			p = p->next;
			tmp--;
		}//将p指向中点

		TreeNode* root = new TreeNode(p->val);//p指向的中点值即为root
		root->left = generate(head, mid - 1);//递归左侧
		root->right = generate(p->next, len - mid);//递归右侧
		return root;
	}
};
