#include<iostream>
#include<vector>
#include<tree>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createbsthelper(TreeNode* root,int key){
if(root == NULL){
    return new TreeNode(key);
}
if(root->val >= key){
root->left = createbsthelper(root->left,key);
}else{
root->right = createbsthelper(root->right,key);
}
return root;
}

TreeNode* createbst(){
TreeNode* root = NULL;
int x;
cin>>x;
while(x!=-1){
    root = createbsthelper(root,x);
    cin>>x;
}

return root;
}
TreeNode* searchbst(TreeNode* root,int key){
if(root==NULL || root->val == key){
return root;
}
if(root->val >= key){
    root->left = searchbst(root->left,key);
}else{
    root->right = searchbst(root->right,key);
}

return NULL;
}
TreeNode* getMin(TreeNode* root){
    if(root==NULL){
        return root;
    }
    TreeNode* cur = root;
    while(cur && cur->left){
        cur = cur->left;
    }

    return cur;
}
TreeNode* getMax(TreeNode* root){
    if(root==NULL){
        return root;
    }
    TreeNode* cur = root;
    while(cur && cur->right){
        cur = cur->right;
    }
    return cur;
}
TreeNode* deletebst(TreeNode* root,int key){
if(root==NULL){
    return root;
}
if(root->val > key){
root->left = deletebst(root->left,key);
}else if(root->val  < key){
root->right = deletebst(root->right,key);
}else{
    if(root->left == NULL){
        TreeNode* tmp = root->right;
        delete(root);
        return tmp;
    }else if(root->right == NULL){
        TreeNode* tmp = root->left;
        delete(root);
        return tmp;
    }else{
        // Get inorder successor
        TreeNode* tmp = getMin(root->left);
        // copy inorder successor to root
        root->val = tmp->val;
        // delete first copied inorder successor
        root->right = deletebst(root->right,tmp->val);
    }

}

return root;
}

void successor_and_predecessor(TreeNode* root,TreeNode* &suc,TreeNode* &pre,int key){
    if(root==NULL){
        return;
    }
    
        if(root->val == key){

        if(root->left!=NULL){
            TreeNode* tmp = getMax(root->left);
            pre = tmp;
        }else if(root->right!=NULL){
            TreeNode* tmp = getMin(root->right);
            suc = tmp;
        }

        return;
    }
    if(root->val > key){
        suc = root;
        successor_and_predecessor(root->left,suc,pre,key);
    }else if(root->val < key){
        pre = root;
        successor_and_predecessor(root->right,suc,pre,key);
    } 
    return ;
} 

bool isBST(TreeNode* root){
    if(root== NULL){
        return true;
    }
    if(root->left!=NULL && getMax(root->left)->val > root->val ){
        return false;
    }
    if(root->right!=NULL && getMin(root->right)->val < root->val){
        return false;
    }

    if(!isBST(root->left) && !isBST(root->right)){
        return false;
    }
    return true;
}

/*
    Various ways;
    O(n) and O(n) - My Method, Traversal is improved my morris traversal 
    for better efficiency
    O(n) and O(1) - Morris Traversal - Best

    Try Morris Traversal for the same once
*/
vector<TreeNode* > vt;
void capture(TreeNode* root){
if(root==NULL)return;

capture(root->left);
vt.push_back(root);
capture(root->right);
}

void printKmax_min(TreeNode* root,int k){
capture(root);
int n = vt.size();
// Max
cout << vt[n-k+1]->val;
// Min 
cout << vt[k-1]->val;
}
void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val ;
    inorder(root->right);
}

// One more variation of this question
void merge(TreeNode* root1, TreeNode* root2){
if(root1 == NULL && root2 == NULL){
    return;
}
if(root1==NULL){
    return inorder(root2);
}
if(root2==NULL){
    return inorder(root1);
}

TreeNode* tmp1 = root1;
TreeNode* prev1 = NULL;

TreeNode* tmp2 = root2;
TreeNode* prev2 = NULL;

if(tmp1->val < tmp2->val){
cout << tmp1->val << " ";
if(prev1 == NULL){
merge(root1->right,root2);
}else{
prev1->left = tmp1->right;
merge(root1,root2);
}
}else{
cout << tmp2->val << " ";
if(prev2 == NULL){
    merge(root1,root2->right);
}else{
    prev2->left = tmp2->right;
    merge(root1,root2);
}
}
}

/*Few Variations to take care of*/
TreeNode* prev;
void FlattenBST(TreeNode* root,TreeNode* &prev){
if(root==NULL){
    return;
}    
FlattenBST(root->right,prev);
FlattenBST(root->left,prev);
root->left = NULL;
root->right = prev;
prev = root;
}
/*
prev = NULL;
FlattenBST(root,prev);
*/

TreeNode* lcaBST(TreeNode* root,int key1,int key2){
    if(root==NULL){
        return NULL;
    }

    if(root->left && root->val > key1 && root->val > key2){
        return lcaBST(root->left,key1,key2);
    }
    if(root->right && root->val < key1 && root->val < key2){
        return lcaBST(root->right,key1,key2);
    }
    return root;
}
int main(){

}