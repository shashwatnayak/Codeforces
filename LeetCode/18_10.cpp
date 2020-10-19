class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root==NULL){
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        TreeNode* leftlca = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightlca = lowestCommonAncestor(root->right,p,q);
        
        if(leftlca && rightlca)return root;
        
        return (leftlca!=NULL) ? leftlca:rightlca;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        if((root->val>=p->val && root->val <=q->val) ||
           (root->val<=p->val && root->val >=q->val))
        return root;
         if(root->val>p->val && root->val >q->val)
           return  lowestCommonAncestor(root->left,p,q);
          else
           return  lowestCommonAncestor(root->right,p,q);
    }
};

class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1 + max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh-rh)<=1 && isBalanced(root->left)&&isBalanced(root->right)){
            return true;
        }
        return false;
    }
};