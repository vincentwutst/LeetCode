class Solution {
public:
    void connect(TreeLinkNode *root) {
        //NULL or has no children, nothing to do.
        if(root == NULL || root->left == NULL) 
          return;
        while(root){
        if(root->left == NULL) return;
        TreeLinkNode *p = root;
        while(p != NULL)
        {
          p->left->next = p->right;
          if(p->next)
          p->right->next = p->next->left;
          p = p->next;
        }
        root = root->left;
        }
    }
};
