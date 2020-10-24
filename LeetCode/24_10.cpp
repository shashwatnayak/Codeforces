// Morris Traversal for better Inorder
// Stack Solution was used in traversals
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        
        TreeNode* current=root;
        
        while(current!=NULL)
        {
            if(current->left==NULL)
            {
                v.push_back(current->val);
                current=current->right;
            }
            else{
                TreeNode* preNode=current->left;
                
                while(preNode->right!=NULL && preNode->right!=current)
                    preNode=preNode->right;
                
                if(preNode->right==current)
                {
                    v.push_back(current->val);
                    preNode->right=NULL;
                    current=current->right;
                }
                else
                {
                    preNode->right=current;
                    current=current->left;
                }
            }
        }
        return v;
    }
};

////O(n) time and O(1) space
//The basic idea is the postorder traversal can be considered as a reverse process of preorder traversal. Therefore, we just need to change all left child to right child and always insert elements at the beginning of the vector.

//PostOrder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> values;
        while (current != NULL){
            if (current->right == NULL){
                // Always insert at the beginning
                values.insert(values.begin(), current->val);
                current = current->left; // Reverse of preorder traversal
            }else{
                TreeNode* predecessor = findPredecessor(current);
                if (predecessor->left == NULL){
                    // Link to current
                    predecessor->left = current;
                    values.insert(values.begin(), current->val);
                    current = current->right;   // Reverse of preorder
                }else{
                    predecessor->left = NULL;
                    current = current->left;
                }
            }
        }
        return values;
    }
    TreeNode* findPredecessor(TreeNode* current){
        // Reverse of preorder traversal
        TreeNode* predecessor = current->right; 
        while (predecessor->left != NULL && predecessor->left != current){
            predecessor = predecessor->left;
        }
        return predecessor;
    }
};
//PreOrder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        TreeNode *current = root;
        while(current != NULL){
            if (current->left == NULL){
                values.push_back(current->val);
                current = current->right;
            }else{
                TreeNode *predecessor = findPredecessor(current);
                if (predecessor->right == NULL){
                    predecessor->right = current;
                    values.push_back(current->val);
                    current = current->left;
                }else{
                    predecessor->right = NULL;
                    current = current->right;
                }
            }
        }
        return values;
    }
    TreeNode* findPredecessor(TreeNode* current){
        TreeNode* predecessor = current->left;
        while(predecessor->right != NULL && predecessor->right != current){
            predecessor = predecessor->right;
        }
        return predecessor;
    }
};
//InOrder
//The difference between inorder and preorder is the place for inserting elements to the vector.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        TreeNode *current = root;
        while (current != NULL){
            if (current->left == NULL){
                values.push_back(current->val);
                current = current->right;
            }else{
                TreeNode* preDecessor = findPredecessor(current);
                if (preDecessor->right == NULL){
                    preDecessor->right = current;
                    current = current->left;
                }else{
                    preDecessor->right = NULL;
                    values.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return values;
    }
    TreeNode* findPredecessor(TreeNode* current){
        TreeNode* preDecessor = current->left;
        while (preDecessor->right != NULL && preDecessor->right != current){
            preDecessor = preDecessor->right;
        }
        return preDecessor;
    }
};
